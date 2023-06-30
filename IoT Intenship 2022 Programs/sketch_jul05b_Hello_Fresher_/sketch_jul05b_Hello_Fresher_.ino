//How to use Serial.println() and Serial.print()
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print("Hello ");
delay(100);
Serial.println("Fresher");
delay(50);
Serial.println("Welcome to SIT");
delay(200);
}
