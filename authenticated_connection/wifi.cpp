#include "config.h"
#include <WiFiNINA.h>

void setupWiFi() {
  DEBUG_PRINT("Connecting to WiFi");
  while (WiFi.begin(WIFI_SSID, WIFI_PASSWORD) != WL_CONNECTED) {
    DEBUG_PRINT(".");
    delay(500);
  }
  DEBUG_PRINTLN("\nWiFi connected");
}
