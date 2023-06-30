//How to connect Humidity sensor
#include<DHT.h>
#define Dpin 23
#define Dtype DHT11

DHT dht(Dpin, Dtype);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();

}

float t, h,f;
void loop() {
   delay(500);
  // put your main code here, to run repeatedly:
  h = dht.readHumidity();
  t = dht.readTemperature();
  f = dht.readTemperature(true);
  if(isnan(t)||isnan(h)||isnan(f)){
    //isnan->is not a num
    Serial.println("Check the Connection of DHT11.");
    return;
  }
  Serial.print(F("Humidity = "));
  Serial.print(h);
  Serial.print("% ");

  Serial.print(F("Temperature = "));
  Serial.print(t);
  Serial.println(F("°c "));
  Serial.println(f);
  Serial.println(F("°F "));
  
  
}
