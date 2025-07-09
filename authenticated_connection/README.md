## 🔐 Authenticated Connection

📁 authenticated_connection/

This mode uses full credentials for secure access and receives device events like online/offline status.

In config.h, define:

```h
#define DEVICE_NAME     "authenticated_device"
#define USER_ID         "your_user_id"
#define DEVICE_ID       "your_device_id"
#define API_KEY         "api_key_abc123"
#define MQTT_USERNAME   "mqtt_username"
#define MQTT_PASSWORD   "mqtt_password"
#define TOPIC           "home/livingroom/light"
```

In your sketch:

```c
void setup() {
  buildAutomatedhubConfig();
  setupWiFi();
  setupMQTT();
}

void loop() {
  handleMQTTConnection();
}
```

📡 Subscribes to: `user_id/home/livingroom/light/control`
🖥️ Receives control messages from the web UI or MQTT clients
