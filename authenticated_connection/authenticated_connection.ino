#include "config.h"
#include "wifi.h"
#include "mqtt.h"

void setup() {
  DEBUG_BEGIN(115200);
  pinMode(DEVICE_PIN, OUTPUT);
  digitalWrite(DEVICE_PIN, LOW);

  buildAutomatedhubConfig();
  setupWiFi();
  setupMQTT();
}

void loop() {
  handleMQTTConnection();
}
