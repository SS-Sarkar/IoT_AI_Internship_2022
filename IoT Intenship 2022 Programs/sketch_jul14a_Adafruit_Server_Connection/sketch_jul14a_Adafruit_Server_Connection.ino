//Adafruit sever connection 
#include <WiFi.h>

#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883
#define AIO_USERNAME  "SadSCB"
#define AIO_KEY  "aio_nudR532ZjQMR7ji9c41Bt31inDHU"
WiFiClient client;

Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

Adafruit_MQTT_Subscribe Demolight = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Demolight");
boolean MQTT_connect();

boolean MQTT_connect() {  int8_t ret; if (mqtt.connected()) {    return true; }  uint8_t retries = 3;  while ((ret = mqtt.connect()) != 0) { mqtt.disconnect(); delay(2000);  retries--;if (retries == 0) { return false; }} return true;}

void setup()
{
  Serial.begin(9600);
  WiFi.disconnect();
  delay(1000);
   WiFi.begin("dlink","");
  Serial.println("Try to connect to dlink");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print(".");

  }
  Serial.println("Connected");

  mqtt.subscribe(&Demolight);

}


void loop()
{

    if (MQTT_connect()) {
      Adafruit_MQTT_Subscribe *subscription_name;
      while ((subscription_name = mqtt.readSubscription(5000))) {
        if (subscription_name == &Demolight) {
          Serial.println(((char *)Demolight.lastread));

        }

      }

    }

}
