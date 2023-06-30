//Send Moisture data to Adafruit Server

#include <WiFi.h>

#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

String  data;
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883
#define AIO_USERNAME  "SadSCB"
#define AIO_KEY  "aio_nudR532ZjQMR7ji9c41Bt31inDHU"
WiFiClient client;

Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

Adafruit_MQTT_Subscribe Demolight = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/Demolight");
int  i;
int  Count;
boolean MQTT_connect();

boolean MQTT_connect() {  int8_t ret; if (mqtt.connected()) {    return true; }  uint8_t retries = 3;  while ((ret = mqtt.connect()) != 0) { mqtt.disconnect(); delay(2000);  retries--;if (retries == 0) { return false; }} return true;}

Adafruit_MQTT_Publish Moisture = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Moisture");
void setup()
{
  data = 3000;
pinMode(23, OUTPUT);
pinMode(34, INPUT);
Serial.begin(9600);
i = 0;
Count = 0;
  WiFi.disconnect();
  delay(1000);
   WiFi.begin("dlink","");
  Serial.println("Try to connect to dlink");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print(".");

  }
  Serial.println("Connected");
  Serial.println("Your IP is:");
  Serial.println((WiFi.localIP().toString()));

  mqtt.subscribe(&Demolight);
  i = analogRead(34);

}


void loop()
{

    i = (random(1000,4000));
    Count = Count == 1;
    if (MQTT_connect()) {
      Adafruit_MQTT_Subscribe *subscription_name;
      while ((subscription_name = mqtt.readSubscription(5000))) {
        if (subscription_name == &Demolight) {
          data = ((char *)Demolight.lastread);
          if (data == "ON") {
            Serial.println("Light On");
            digitalWrite(23, 0);

          } else if (data == "OFF") {
            Serial.println("Light Off");
            digitalWrite(23, 1);
          }

        }

      }
      if (Count == 1) {
        if (Moisture.publish(i)) {
          Serial.println("Data Sent");
          Serial.println(i);

        }

      } else if (Count == 7) {
        Count = 0;
      }

    }
}
