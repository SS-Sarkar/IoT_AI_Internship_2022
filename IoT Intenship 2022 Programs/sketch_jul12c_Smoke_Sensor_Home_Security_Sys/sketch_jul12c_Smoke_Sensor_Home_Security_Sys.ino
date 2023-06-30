//Home security model using Smoke sensor
#include<DHT.h>
#define Dpin 23
#define Dtype DHT11

DHT dht(Dpin, Dtype);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();

pinMode(21,OUTPUT);
pinMode(34,OUTPUT);
}
int pushData = 0;
float t, h,f;
int ADC_data = 0;
float Vout = 0;
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
  
 
  ADC_data = analogRead(34);
Serial.print("Analog Data = ");
Serial.println(ADC_data);
Vout = ((3.3*ADC_data)/4096);
Serial.print("Voltage out = ");
Serial.println(Vout);
if(ADC_data>=1000){
  digitalWrite(21,1);
}
else if (ADC_data<1000){
  digitalWrite(21,0);
}

delay(500);
}
