//Project on Weather Monitering System

#include<DHT.h>
#define Dpin 23
#define Ana 34
#define An 33
#define Dtype DHT11

DHT dht(Dpin, Dtype);

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();

}

  int ADC_data = 0, An_data = 0;
  float Vout = 0, Vrout = 0;
  float t, h,f;
  
void loop() {
   delay(500);
    // put your main code here, to run repeatedly:
    h = dht.readHumidity();
    t = dht.readTemperature();
    f = dht.readTemperature(true);

    ADC_data = analogRead(Ana);
    Serial.print("LDR Analog Data = ");
    Serial.println(ADC_data);
    Vout = ((3.3*ADC_data)/4096);
    Serial.print("Voltage out = ");
    Serial.println(Vout);
    delay(100);

      if (ADC_data>= 3000)
   { 
     Serial.println("NIGHT");
   }
    else if (ADC_data < 3000)
   {
    Serial.println("DAY");
      if(ADC_data > 110)
      {
        Serial.println("CLOUDY");
      }
      else if(ADC_data < 50)
      {
        Serial.println("SUNNY");
      }
    }

  if(isnan(t)||isnan(h)||isnan(f))
  {
    //isnan->is not a num
    Serial.println("Check the Connection of DHT11.");
    return;
  }
    Serial.print(F("Humidity = "));
    Serial.print(h);
    Serial.println("% ");
  
    Serial.print(F("Temperature = "));;
    Serial.print(t);
    Serial.println(F("°c "));
    Serial.print(F("Temperature = "));
    Serial.print(f);
    Serial.println(F("°F "));
    Serial.println("");

      An_data = analogRead(An);
    Serial.print("Rain Sensor Analog Data = ");
    Serial.println(An_data);
    Vrout = ((3.3*An_data)/4096);
    Serial.print("Voltage out = ");
    Serial.println(Vrout);

  if (An_data >= 3400)
  { 
    Serial.println("NOT RAINING");
  }
  else if (An_data > 1000 && An_data < 2000)
  {
    Serial.println("MODERATE RAIN");
  }
  else if (An_data < 1000)
  {
    Serial.println("HEAVY RAIN");
  }
  
  delay(3000);
  
}
