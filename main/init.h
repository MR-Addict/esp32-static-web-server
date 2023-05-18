void init(uint8_t led, uint32_t baud_rate, const char* ssid, const char* password) {
  // init led
  pinMode(led, OUTPUT);
  Serial.begin(baud_rate);

  // init SPIFFS
  if (!SPIFFS.begin()) {
    Serial.println("Failed to mount SPIFFS");
    return;
  }

  // init wifi
  WiFi.begin(ssid, password);
  Serial.printf("Connecting to %s", ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print('.');
  }

  // indicate wifi connected
  digitalWrite(led, HIGH);
  Serial.printf("\nLocal IP: %s", WiFi.localIP().toString().c_str());
}
