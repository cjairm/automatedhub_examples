#include "config.h"
#include <ArduinoJson.h>
#include <PubSubClient.h>
#include <WiFiNINA.h>

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

unsigned long lastReconnectAttempt = 0;

void mqttCallback(char *topic, byte *payload, unsigned int length) {
  DEBUG_PRINT("Message received on topic: ");
  DEBUG_PRINTLN(topic);

  StaticJsonDocument<200> doc;
  DeserializationError error = deserializeJson(doc, payload, length);
  if (error) {
    DEBUG_PRINT("deserializeJson() failed: ");
    DEBUG_PRINTLN(error.f_str());
    return;
  }

  const char *state = doc["state"];
  if (!state)
    return;

  if (strcmp(state, "on") == 0) {
    digitalWrite(DEVICE_PIN, HIGH);
    DEBUG_PRINTLN("Pin turned ON");
  } else if (strcmp(state, "off") == 0) {
    digitalWrite(DEVICE_PIN, LOW);
    DEBUG_PRINTLN("Pin turned OFF");
  }
}

bool reconnectMQTT() {
  DEBUG_PRINT("Connecting to MQTT... ");
  if (mqttClient.connect(mqttClientId.c_str())) {
    DEBUG_PRINTLN("connected");
    mqttClient.subscribe(topic.c_str());
    return true;
  } else {
    DEBUG_PRINT("failed, rc=");
    DEBUG_PRINTLN(mqttClient.state());
    return false;
  }
}

void setupMQTT() {
  mqttClient.setServer(MQTT_SERVER, MQTT_PORT);
  mqttClient.setCallback(mqttCallback);
  reconnectMQTT();
}

void handleMQTTConnection() {
  if (!mqttClient.connected()) {
    unsigned long now = millis();
    if (now - lastReconnectAttempt > RECONNECT_INTERVAL) {
      lastReconnectAttempt = now;
      if (reconnectMQTT()) {
        lastReconnectAttempt = 0;
      }
    }
  } else {
    mqttClient.loop();
  }
}
