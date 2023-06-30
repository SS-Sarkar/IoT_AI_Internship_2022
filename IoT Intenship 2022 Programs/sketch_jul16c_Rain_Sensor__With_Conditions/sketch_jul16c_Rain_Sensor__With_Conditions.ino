//Raindrop sensor and buzzer
 #define An 33
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}
int An_data = 0;
float Vrout = 0;
void loop() {
  // put your main code here, to run repeatedly:
An_data = analogRead(An);
Serial.print("Analog Data = ");
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
