#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#define USE_SERIAL Serial
ESP8266WiFiMulti WiFiMulti;
void setup() {
   USE_SERIAL.begin(9600);
  // USE_SERIAL.setDebugOutput(true);
   USE_SERIAL.println();
   USE_SERIAL.println();
   USE_SERIAL.println();
   for(uint8_t t = 4; t > 0; t--) {
     //  USE_SERIAL.printf("[SETUP] WAIT %d...\n", t);
       USE_SERIAL.flush();
       delay(1000);
   }
   WiFi.mode(WIFI_STA);
   // provide our SSID and Password for WIFI network connection
   WiFiMulti.addAP("WLAN-978831", "1105741512128512");
}
void loop() {
   // wait for WiFi connection
   if((WiFiMulti.run() == WL_CONNECTED)) {
       HTTPClient http;
       USE_SERIAL.println("Sending Get Request to Server.......");
       http.begin("http://192.168.2.108:888/"); //HTTP URL for hosted server(local server)
       //192.168.43.161 - HOST     PORT: 3000 and /api is the target api we need to hit to get response
       int httpCode = http.GET();
      // USE_SERIAL.println("After GET Request");
       // httpCode will be negative on error
       if(httpCode > 0) {
           if(httpCode == HTTP_CODE_OK) {
             //HTTP_CODE_OK means code == 200
               String payload = http.getString();// gives us the message received by the GET Request
               USE_SERIAL.println(payload);// Displays the message onto the Serial Monitor
           }
       } else {
           USE_SERIAL.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
       }
       http.end();
   }
   delay(5000);// repeat the cycle every 5 seconds.
}
