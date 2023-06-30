//How to give data from computert to device
void setup() {
  // put your setup code here, to run once:
Serial.begin(38400);
}
char data;
void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()>0){
  data = Serial.read();//ESP 32 ip
  Serial.print("Incoming Data from ESP32 = ");
  Serial.println(data);//ESP32 op
  delay(200);
 }
}
