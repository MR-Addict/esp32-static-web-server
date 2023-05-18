AsyncWebServer server(80);

// handle OPTIONS and 404 request
void handleNotFound(AsyncWebServerRequest* request) {
  String url = request->url();

  // end with /
  if (url.endsWith("/")) {
    url += "index.html";
    if (SPIFFS.exists(url)) {
      request-> send(SPIFFS, url, "text/html");
    } else {
      request->send(404);
    }
  }
  else if (request->method() == HTTP_OPTIONS) {
    request->send(200);
  } else {
    request->send(404, "text/plain", "404 | Not Found");
  }
}

void setupServer() {
  DefaultHeaders::Instance().addHeader("Server", "ESP Async Web Server");
  DefaultHeaders::Instance().addHeader("Access-Control-Allow-Origin", "*");
  DefaultHeaders::Instance().addHeader("Access-Control-Allow-Methods", "*");
  DefaultHeaders::Instance().addHeader("Access-Control-Allow-Headers", "*");

  server.serveStatic("/", SPIFFS, "/");
  server.onNotFound(handleNotFound);

  server.begin();
}
