# Social Engineering & Network Security Prototype (Captive Portal)

## Legal & Ethical Disclaimer
 This project was developed to demonstrate the vulnerabilities inherent in public, unencrypted WiFi networks. The use of this tool against individuals or networks without explicit permission is illegal and unethical. The author (Me) assumes no liability for misuse.

## Project Overview
This project uses an **ESP8266** microcontroller to simulate a "Man-in-the-Middle" (MitM) scenario. It creates a rogue Access Point (AP) and uses DNS redirection to force users onto a custom login page, demonstrating how easily credentials can be harvested on insecure networks.

## Technical Features
* **DNS Hijacking:** Intercepts all DNS requests and redirects them to the local gateway IP.
* **Multi-OS Compatibility:** Includes specific endpoint handlers for Android (`generate_204`), Apple (`hotspot-detect.html`), and Windows to trigger native "Sign-in to Network" notifications.
* **Asynchronous Web Server:** Serves a custom-built HTML login interface.
* **Data Capture:** Implements HTTP POST handling to log submitted credentials to the Serial interface for auditing.

## Hardware Requirements
* **Microcontroller:** ESP8266 (NodeMCU or D1 Mini)
* **Development Environment:** Arduino IDE / PlatformIO

## Setup & Installation
1. Clone the repository:
   `git clone https://github.com/yourusername/esp8266-captive-portal-security-poc.git`
2. Open `src/captive_portal.ino` in the Arduino IDE.
3. Install the **ESP8266 board library**.
4. Upload the code to your device.
5. Connect to the "FreeWiFi" network and observe the redirect logic.

## Security Mitigation
This project serves to highlight why users should:
1. Avoid unencrypted public WiFi.
2. Use a VPN on public networks.
3. Enable Multi-Factor Authentication (MFA) on all accounts to mitigate the impact of stolen credentials.
