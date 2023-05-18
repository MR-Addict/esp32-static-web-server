# ESP32 Static Web Server

Using ESP32 as static web server, you can have a closer look at **server.h** for ESP32 server.

## 1. Libraries

You need to install [ESP32 SPIFFS Uploader](https://github.com/me-no-dev/arduino-esp32fs-plugin/releases) for uploading static data to ESP32 SPIFFS system.

You may need to install needed libraries in **libraries** folder.

```cpp
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
```

## 2. Static files

I'm using my another astro project which generated static files for serving.

- [https://github.com/MR-Addict/quote](https://github.com/MR-Addict/quote)

## 3. Important code

```cpp
AsyncWebServer server(80);

// handle OPTIONS and 404 request
void handleNotFound(AsyncWebServerRequest* request) {
  ...
}

void setupServer() {
  ...

  server.serveStatic("/", SPIFFS, "/");
  server.onNotFound(handleNotFound);

  server.begin();
}
```

> You can even using esp32 as template processing engine, you can have a look on it github page:
>
> - [https://github.com/me-no-dev/ESPAsyncWebServer](https://github.com/me-no-dev/ESPAsyncWebServer)
