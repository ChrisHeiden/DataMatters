#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>

#ifndef ClientConnection_h
#define ClientConnection_h

class ClientConnection
{
  public:
    ClientConnection();
    void readServer();
    String getPayload();

  private:
    String _pass;
    String _ssid;
    String _payload;
    String _url;
 
    ESP8266WiFiMulti _wiFiMulti;
};
#endif
