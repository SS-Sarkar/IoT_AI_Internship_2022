#include<WiFi.h>
#define ssid "dlink"
#define pass ""
void setup() {
  Serial.begin(9600);
  WiFi.disconnect();
  delay(2000);
  WiFi.begin(ssid,pass);
  Serial.println("Try to connect");
  while(WiFi.status() !=WL_CONNECTED){
    delay(200);
    Serial.print(".");
    
  }
  Serial.println("Connected");
}
int moist;
void loop() {
  // put your main code here, to run repeatedly:

}
