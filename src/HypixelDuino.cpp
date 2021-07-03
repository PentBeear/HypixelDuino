#include <HypixelDuino.hpp>

void HypixelAPI::selfDestruct(){
    delete this;
}


bool HypixelAPI::getOnlineStatus(char* UUID,WiFiClientSecure client){
    client.setInsecure(); // a big nono but it works here

    // Builds URL
    char URL[500] = "";
    strcpy(URL,endpoint);
    strcat(URL,localKey);
    strcat(URL,"&uuid=");
    strcat(URL,UUID);
    //Serial.println(URL);

    // Begins the get request and stores the result
    http.begin(client,URL);
    int httpCode = http.GET();
    String payload = http.getString();
    char payloadChar[payload.length() + 1];
    payload.toCharArray(payloadChar,payload.length());
    strcat(payloadChar,"}");
    http.end();

    //Serial.println(payloadChar);

    // Deserializes and parses the result
    DeserializationError error = deserializeJson(doc, payloadChar);
    // Test if parsing succeeds.
    if (error) {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(error.f_str());
        return false;
    } else {
        bool result = doc["session"]["online"];
        //Serial.println(doc.isNull());
        //Serial.println(result);
        return result;
    }

    
}

char* HypixelAPI::getKey(){
    return localKey;
}

void HypixelAPI::setKey(char* key){
    strcpy(localKey,key);
}


