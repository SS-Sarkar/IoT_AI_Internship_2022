//Sending data to blynk server from DHT11

#define BLYNK_TEMPLATE_ID "TMPL-liaraQT"
#define BLYNK_DEVICE_NAME "DHT11"
#define BLYNK_AUTH_TOKEN "w6B1meVgpd4tBIrtad4ASs_slBbMqRg8"

#define BLYNK_PRINT Serial 

#include<DHT.h>
#define Dpin 23
#define Dtype DHT11

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "dlink";
char pass[] = "";

DHT dht(Dpin, Dtype);
BlynkTimer timer;
float t, h,f; 
void myTimerEvent()
{
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
  
  
  Blynk.virtualWrite(V0, h);
  Blynk.virtualWrite(V1, t);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  Blynk.begin(auth,ssid, pass);
  timer.setInterval(3000L, myTimerEvent); 
  delay(1000);
   
}

void loop() {
  Blynk.run();
  timer.run();
  // put your main code here, to run repeatedly:
}
