#include <Arduino.h>
#include <myWiFiManager.h>
#include <PubSubClient.h>
#include <myMQTT.h>
#include <common.h>


#define SWITCHPIN 2

WiFiClient espClient;
PubSubClient mqttClient(espClient);

uint8_t state = LOW;

void setup() {
  Serial.begin(115200);
  delay(1000);

  pinMode(SWITCHPIN, INPUT_PULLUP);
  digitalWrite(SWITCHPIN, LOW);

  const int isConnected = setupMyWiFi();
  if(isConnected)
  {
    Serial.println("WIFI [connected]");
    Serial.println("MQTT [connecting]");
    mqttClient.setServer(MQTT_BROKER, MQTT_PORT);
    // mqttClient.setCallback(mqttCallback);
    initMQTTBroker(&mqttClient);
  }
  else
  {
    Serial.println("MQTT [unable to Connect]");
  }

}

void loop() {
  if(!mqttClient.connected())
  {
    mqttClient.connect(MQTT_CLIENT_ID);
  }
  mqttClient.loop();
  
  uint8_t readState = digitalRead(SWITCHPIN);

  if( readState != state)
  {

    if(readState == HIGH) pusblishMessage(&mqttClient, "OPEN");
    if(readState == LOW) pusblishMessage(&mqttClient, "CLOSED");

    state = readState;
    delay(500);
  }

}