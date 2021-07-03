#include <Arduino.h>
#include <HypixelDuino.hpp>

HypixelAPI test = HypixelAPI("");
WiFiClientSecure client;


const char* ssid = "";
const char* password = "";
 
void setup () {
 
  Serial.begin(115200);
 
  WiFi.begin(ssid, password);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
 
    delay(1000);
    Serial.print(".");
 
  }

  Serial.println("\nConnected");

  Serial.println(test.getOnlineStatus("5e35be48-c37f-41b4-8726-28dfd35fadaf",client));

 
}
 

void loop() {
  // put your main code here, to run repeatedly:
}