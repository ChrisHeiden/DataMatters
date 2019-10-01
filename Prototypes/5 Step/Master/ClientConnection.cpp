#include "ClientConnection.h"

ClientConnection::ClientConnection()
{
  _ssid = "WLAN-978831";
  _pass = "1105741512128512";
  _url = "http://192.168.2.108:8889/";
  Serial.println();
  Serial.println();
  Serial.println();
  for(uint8_t t = 4; t > 0; t--)
  {
    Serial.flush();
    delay(1000);
  }
  WiFi.mode(WIFI_STA);
  _wiFiMulti.addAP(_ssid.c_str(), _pass.c_str());
}

void ClientConnection::readServer()
{
   if((_wiFiMulti.run() == WL_CONNECTED)) {
       HTTPClient http;
       Serial.println("Sending Get Request to Server.......");
       http.begin(_url); //HTTP URL for hosted server(local server)
       int httpCode = http.GET();
       if(httpCode > 0) {
           if(httpCode == HTTP_CODE_OK) {
               _payload = http.getString();// gives us the message received by the GET Request
               Serial.println(_payload);// Displays the message onto the Serial Monitor
           }
       } else {
           Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
       }
       http.end();
   }
   delay(5000);// repeat the cycle every 5 seconds.
}

String ClientConnection::getPayload()
{
  return _payload;
}
