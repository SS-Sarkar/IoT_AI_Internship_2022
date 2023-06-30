void setup() {
  // put your setup code here, to run once:


}

void loop() {
  // put your main code here, to run repeatedly:
pinMode(23, OUTPUT);
pinMode(22, OUTPUT);
pinMode(21, OUTPUT);
digitalWrite(23, 1);
digitalWrite(22, 0);
digitalWrite(21, 0);
delay(1000);
digitalWrite(23, 1);
digitalWrite(22, 1);
digitalWrite(21, 0);
delay(1500);
digitalWrite(23, 1);
digitalWrite(22, 1);
digitalWrite(21, 1);
delay(2500);
digitalWrite(23, 1);
digitalWrite(22, 1);
digitalWrite(21, 0);
delay(3500);
digitalWrite(23, 1);
digitalWrite(22, 0);
digitalWrite(21, 0);
delay(4500);
digitalWrite(23, 0);
digitalWrite(22, 0);
digitalWrite(21, 0);
delay(5000);
}
