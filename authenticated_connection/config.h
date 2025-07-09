#ifndef CONFIG_H
#define CONFIG_H

// Enable or disable debug output
#define DEBUG true

#if DEBUG
  #define DEBUG_BEGIN(...) Serial.begin(__VA_ARGS__)
  #define DEBUG_PRINT(x) Serial.print(x)
  #define DEBUG_PRINTLN(x) Serial.println(x)
#else
  #define DEBUG_BEGIN(...)
  #define DEBUG_PRINT(x)
  #define DEBUG_PRINTLN(x)
#endif

extern const char* WIFI_SSID;
extern const char* WIFI_PASSWORD;

extern const char* MQTT_SERVER;
extern const int   MQTT_PORT;

extern const char* API_KEY;
extern const char* DEVICE_NAME;
extern const char* USER_ID;
extern const char* DEVICE_ID;

extern const unsigned long RECONNECT_INTERVAL;

#include <Arduino.h>

extern String mqttClientId;
extern String mqttUsername;
extern String mqttPassword;
extern String topic;

void buildAutomatedhubConfig();

#define DEVICE_PIN 13

#endif
