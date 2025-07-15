#include "config.h"
#include <Arduino.h>

const char* WIFI_SSID = "<wifi-name>";
const char* WIFI_PASSWORD = "<wifi-password>";

const char* MQTT_SERVER = "3.22.201.62";
const int MQTT_PORT = 1883;

const char* MQTT_USERNAME = "office";
const char* MQTT_PASSWORD = "example-of-password";

const char* DEVICE_NAME = "arduino_test";
const char* DEVICE_ID = "<device-id>";
const char* USER_ID = "<user-id>";
const char* API_KEY = "<api-key>";
const char* TOPIC = "home/office/#";

const unsigned long RECONNECT_INTERVAL = 10000;

String mqttClientId;
String mqttUsername;
String mqttPassword;
String topic;

void buildAutomatedhubConfig() {
  mqttClientId = String(API_KEY) + "__" + String(DEVICE_NAME);
  mqttUsername = String(DEVICE_ID) + ":" + String(MQTT_USERNAME);
  mqttPassword = String(MQTT_PASSWORD);
  
  topic = String(USER_ID) + "/" + String(TOPIC);
}

