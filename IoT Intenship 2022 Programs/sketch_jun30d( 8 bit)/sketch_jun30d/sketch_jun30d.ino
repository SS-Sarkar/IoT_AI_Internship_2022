#define L1 15
#define L2 17
#define L3 19
void setup() {
  // put your setup code here, to run once:
pinMode(L1, OUTPUT);
pinMode(L2, OUTPUT);
pinMode(L3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(L1, 0);
digitalWrite(L2, 0);
digitalWrite(L3, 0);
delay(1000);
digitalWrite(L1, 0);
digitalWrite(L2, 0);
digitalWrite(L3, 1);
delay(1000);
digitalWrite(L1, 0);
digitalWrite(L2, 1);
digitalWrite(L3, 0);
delay(1000);
digitalWrite(L1, 0);
digitalWrite(L2, 1);
digitalWrite(L3, 1);
delay(1000);
digitalWrite(L1, 1);
digitalWrite(L2, 0);
digitalWrite(L3, 0);
delay(1000);
digitalWrite(L1, 1);
digitalWrite(L2, 0);
digitalWrite(L3, 1);
delay(1000);
digitalWrite(L1, 1);
digitalWrite(L2, 1);
digitalWrite(L3, 0);
delay(1000);
digitalWrite(L1, 1);
digitalWrite(L2, 1);
digitalWrite(L3, 1);
delay(1000);
}
