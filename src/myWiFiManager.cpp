#include <Arduino.h>
#include "myWiFiManager.h"
#include <common.h>



int setupMyWiFi(){
    WiFi.mode(WIFI_STA);
    WiFi.begin(SSID, PASS);

    while(WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.println(".");
    } 

    if(WiFi.status() == WL_CONNECTED)
    {
        Serial.begin(115200);
        Serial.println("WiFi connected");
        Serial.println(WiFi.localIP());
        return 1;
    }

    return 0;
    
}