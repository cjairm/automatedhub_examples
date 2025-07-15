#include "config.h"
#include <Arduino.h>

const char* WIFI_SSID = "<wifi-name>";
const char* WIFI_PASSWORD = "<wifi-password>";

const char* MQTT_SERVER = "3.22.201.62";
const int MQTT_PORT = 1883;

const char* DEVICE_NAME = "arduino_test";
const char* DEVICE_ID = "<device-id>";
const char* USER_ID = "<user-id>";
const char* API_KEY = "<api-key>";

const unsigned long RECONNECT_INTERVAL = 10000;

String mqttClientId;
String topic;

void buildAutomatedhubConfig() {
  mqttClientId = String(API_KEY) + "__" + String(DEVICE_NAME);
  topic = String(USER_ID) + "/devices/" + String(DEVICE_ID) + "/control";
}

