#include <WiFi.h>

#include <HTTPClient.h>

#include<DHT.h>
#define Dpin 23
#define Dtype DHT11

DHT dht(Dpin, Dtype);

float  temp_data;
float  humi_data;
float  moist_data;
WiFiClient client;

String thingSpeakAddress= "http://api.thingspeak.com/update?";
String writeAPIKey;
String tsfield1Name;
String request_string;

HTTPClient http;

void setup()
{
  temp_data = 0;
humi_data = 0;
moist_data=0;
Serial.begin(9600);
dht.begin();
  WiFi.disconnect();
  delay(1000);
   WiFi.begin("dlink","");
  Serial.println("Connecting to dlink");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.println(".");

  }
  Serial.println("Connected");
  Serial.println((WiFi.localIP().toString()));
pinMode(23,OUTPUT);
pinMode(34,OUTPUT);
}

float t, h ,f,m;
void loop()
{
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
m=analogRead(34);
 if(moist_data>=4000){
        digitalWrite(22,1);
      }
      else if(moist_data<4000){
        digitalWrite(22,0);
      }
  Serial.print(F("Temperature = "));
  Serial.print(t);
  Serial.println(F("°c "));
  Serial.println(f);
  Serial.println(F("°F "));
    Serial.print(("moisture = "));
  Serial.print(m);
 

  
  
temp_data = t;
humi_data = h;
moist_data=m;
  
    if (client.connect("api.thingspeak.com",80)) {
      request_string = thingSpeakAddress;
      request_string += "key=";
      request_string += "HKVG1UDWZTTVNHKY";
      request_string += "&";
      request_string += "field2";
      request_string += "=";
      request_string += temp_data;
       request_string += "&";
      request_string += "field3";
      request_string += "=";
      request_string += humi_data;
        request_string += "&";
      request_string += "field4";
      request_string += "=";
      request_string += moist_data;
      http.begin(request_string);
    
      http.GET();
      http.end();
      
      
      Serial.println("Data sent");

    }
    delay(7000);

}
