#pragma once

#include <ESP8266WiFi.h>
#include <PubSubClient.h>


void pusblishMessage(PubSubClient * mqtt_client, const char * message);

void initMQTTBroker(PubSubClient * mqtt_client);

// CALLBACK FUNCTION FOR RECEIVING MESSAGE
// void mqttCallback(char *topic, byte *payload, unsigned int length);




