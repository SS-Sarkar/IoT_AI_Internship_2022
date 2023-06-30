//Connect to a Mobile's network
#include<WiFi.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.disconnect();
  delay(3000);
  WiFi.begin("moto g(9) 1648","jananahi");
  
  Serial.print("Try to connect ");
  while(WiFi.status() != WL_CONNECTED ){
    delay(200);
    Serial.print(".");
    }
  Serial.println("Connected.");
}

void loop() {
  // put your main code here, to run repeatedly:

}
