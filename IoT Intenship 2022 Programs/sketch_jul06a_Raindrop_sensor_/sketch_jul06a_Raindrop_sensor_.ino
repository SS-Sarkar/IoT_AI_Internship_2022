 //Raindrop sensor and buzzer
 #define Ana 34
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(23, OUTPUT);
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
delay(4000);
if (ADC_data>= 3700)
 { digitalWrite(23 , 0);
 
  }
  else if (ADC_data < 2200)
  {digitalWrite(23 , 1);
    }
}
