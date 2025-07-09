## 🔓 Anonymous Connection

📁 anonymous_connection/

This mode lets you connect and publish/subscribe to public topics without authentication.

In config.h, define:

```h
#define DEVICE_NAME   "demo_device"
#define USER_ID       "your_user_id"
#define DEVICE_ID     "your_device_id"
#define API_KEY       "api_key_abc123"
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

🔌 Subscribes to: `user_id/devices/device_id/control`
