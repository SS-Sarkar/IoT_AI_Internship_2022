//Send data from Humidity sensor to Server
#include <WiFi.h>

#include <HTTPClient.h>

#include<DHT.h>// DHT11
#define Dpin 23
#define Dtype DHT11

DHT dht(Dpin, Dtype);

float  temp_data;
float  humi_data;
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
  
temp_data = t;
humi_data = h;
  
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
      http.begin(request_string);
      http.GET();
      http.end();
      Serial.println("Data sent");

    }
    delay(7000);

}
