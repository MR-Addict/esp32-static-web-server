#include <WiFi.h>
#include <SPIFFS.h>
#include <ESPAsyncWebServer.h>

#include "init.h"
#include "server.h"

const char* ssid = "your_ssid";
const char* password = "your_passowrd";

void setup() {
  init(2, 115200, ssid, password);
  setupServer();
}

void loop() {}
