# AutomatedHub Examples — Arduino MQTT Clients

This repository contains working Arduino examples that connect to the [AutomatedHub MQTT broker](https://automatedhub.io) using **anonymous** and **authenticated** modes.

Use these examples to test, prototype, and learn how to integrate your own hardware devices with the AutomatedHub platform.

---

## 📂 Repository Structure

Each example is self-contained. You can open any `.ino` file in the [Arduino IDE](https://www.arduino.cc/en/software) and upload it to a supported board (like ESP8266 or ESP32).

---

## 🚀 Getting Started

### 1. Clone this Repository

```bash
git clone https://github.com/automatedhub/automatedhub_examples.git
cd automatedhub_examples
```

### 2. Install Arduino Libraries

Install the following libraries via the Library Manager in the Arduino IDE:

- `PubSubClient` (for MQTT)
- `WiFi` or `WiFiEsp` (based on your hardware)

### 3. Configure Your Device

Each example contains a config.h file you must update with:

- `DEVICE_NAME`, `USER_ID`, `DEVICE_ID`, `API_KEY`
- MQTT credentials (only for authenticated mode)
- WiFi credentials (inside `setupWiFi()`)

### 4. Upload to Board

Open either `.ino` file and click Upload. Make sure to select the correct board (ESP8266, ESP32, etc.) and port in the Arduino IDE.

## 🧠 Architecture

Both examples share the same internal helper modules:

- `config.h` / `config.cpp` — Holds user/device-specific identifiers
- `wifi.h` / `wifi.cpp` — Manages WiFi connection logic
- `mqtt.h` / `mqtt.cpp` — Configures and connects MQTT client

## 📋 Notes on Security

Do not upload your real API key, password, or device ID to GitHub.

All examples use placeholders. Replace them with your values from the [AutomatedHub Dashboard](https://automatedhub.io/dashboard).

## 🧪 Testing & Monitoring

Monitor live device status and messages from the Events section on AutomatedHub.

Use the built-in testing tool to simulate publishing/subscribing while debugging your device.

## 🙋 Contributing

Pull requests welcome! Feel free to improve code, add examples, or fix typos. Open an issue if you spot a bug or have a feature request.
