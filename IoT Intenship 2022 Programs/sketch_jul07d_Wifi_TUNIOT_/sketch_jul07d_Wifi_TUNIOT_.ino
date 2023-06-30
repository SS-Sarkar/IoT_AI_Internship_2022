//WiFi using TUNIOT
#include <WiFi.h>

void setup()
{
  Serial.begin(9600);
  WiFi.disconnect();
  delay(3000);
   WiFi.begin("my-net","");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("");

  }
  Serial.print("Connected");

}


void loop()
{

    Serial.print("local IP");
    Serial.println((WiFi.localIP().toString()));
    Serial.print("Gateway IP");
    Serial.println((WiFi.gatewayIP().toString().c_str()));
    Serial.print("Mask");
    Serial.println((WiFi.subnetMask().toString().c_str()));
    delay(500);
   /* 
    Serial.print("Host Name");
    Serial.println((WiFi.hostname()));
   */
}
