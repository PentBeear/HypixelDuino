#ifndef HPD
#define HPD

#include <ArduinoJson.h>
#include <Arduino.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

class HypixelAPI {

    public:
        HypixelAPI(char* apiKey)
        {
            localKey = apiKey;
        }

        void selfDestruct();
        bool getOnlineStatus(char* UUID,WiFiClientSecure client);
        void setKey(char* key);
        char* getKey();

    private:
        char* localKey;
        char* endpoint = "https://api.hypixel.net/status?key=";
        HTTPClient http;
        StaticJsonDocument<512> doc;

};





#endif