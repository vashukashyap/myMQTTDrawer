#include <myMQTT.h>
#include <common.h>


void pusblishMessage(PubSubClient * mqtt_client, const char * message)
{
    mqtt_client->publish(MQTT_TOPIC, message);
}

void initMQTTBroker(PubSubClient * mqtt_client){
    if(!mqtt_client->connected())
    {

        if(mqtt_client->connect(MQTT_CLIENT_ID, MQTT_USERNAME, MQTT_PASSWORD))
        {
            Serial.println("Connecting to MQTT Broker");
            mqtt_client->subscribe(MQTT_TOPIC);
            Serial.println("MQTT [connected]");
        }
        else
        {
            Serial.print("Failed to connect to MQTT broker, rc=");
            Serial.print(mqtt_client->state());
            Serial.println(" try again in 5 seconds");
            delay(5000);
        }
    }
}


// CALLBACK FUNCTION FOR RECEIVING MESSAGE
// void mqttCallback(char *topic, byte *payload, unsigned int length)
// {
//     Serial.print("message received on Topic:");
//     Serial.println(topic);
//     Serial.print("message");
//     for (unsigned int i = 0; i < length; i++)
//     {
//         Serial.print( (char) payload[i] );
//     }
//     Serial.println();
//     Serial.println("-------------");
// }