//Weather sunlight detection using LDR sensor

 #define Ana 34
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(23 , OUTPUT);
}
int ADC_data = 0;
float Vout = 0;

void loop() {
  // put your main code here, to run repeatedly:
ADC_data = analogRead(Ana);
Serial.print("Analog Data = ");
Serial.println(ADC_data);
Vout = ((3.3*ADC_data)/4096);
Serial.print("Voltage out = ");
Serial.println(Vout);
Serial.println("");
delay(1000);
  if (ADC_data>= 3000)
   { 
     Serial.println("NIGHT");
   }
    else if (ADC_data < 3000)
   {
    Serial.println("DAY");
    if(ADC_data > 110){
      Serial.println("CLOUDY");
    }
    else if(ADC_data < 50){
      Serial.println("SUNNY");
    }
  }
}
