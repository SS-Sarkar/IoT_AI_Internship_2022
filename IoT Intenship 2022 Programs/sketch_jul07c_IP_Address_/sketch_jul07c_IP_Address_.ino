//Connect to a WiFi and IP address
#include<WiFi.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  WiFi.disconnect();
  delay(3000);
  WiFi.begin("dlink","");
  Serial.print("Try to connect ");
  while(WiFi.status() != WL_CONNECTED ){
    delay(200);
    Serial.print(".");
    }
  Serial.println("Connected.");
  Serial.print("Local IP: ");
  Serial.println(WiFi.localIP().toString());
}

void loop() {
  // put your main code here, to run repeatedly:

}
