void setup() {
  // put your setup code here, to run once:
pinMode(23, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(23, 1);
delay(1000);
digitalWrite(23, 0);
delay(500);
}
