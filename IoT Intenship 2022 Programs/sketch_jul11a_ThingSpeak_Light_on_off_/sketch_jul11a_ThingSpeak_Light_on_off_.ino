//ThingSpeak_Light on/off
#include <WiFi.h>

#include <ThingSpeak.h>

int  light_data;
WiFiClient client;

void setup()
{
  light_data = 0;
Serial.begin(9600);
ThingSpeak.begin(client);
pinMode(16, OUTPUT);
  WiFi.disconnect();
  delay(1000);
   WiFi.begin("dlink","");
  Serial.println("Connecting");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print(".");

  }
  Serial.println("Connected");

}


void loop()
{

    light_data = (ThingSpeak.readIntField(1795324,1,"QGY6X9EE9ZB8HWKH"));
    Serial.println(light_data);
    //delay(100);
    if (light_data == 1) {
      digitalWrite(16,HIGH);

    } else if (light_data == 0) {
      digitalWrite(16,LOW);
    }

}
