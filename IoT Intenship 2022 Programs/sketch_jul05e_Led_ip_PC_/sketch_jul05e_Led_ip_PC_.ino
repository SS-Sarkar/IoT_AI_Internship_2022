//How to on or off led using command from Computer
void setup() {
  // put your setup code here, to run once:
pinMode(23, OUTPUT); 
Serial.begin(9600);
}
char data;
void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0){
  data = Serial.read();
  Serial.print("Incoming Data from ESP32 = ");
  Serial.println(data);
  delay(200);
if(data == '1'){
digitalWrite(23, 1);
Serial.println("ON");
}
else if(data == '0'){
digitalWrite(23, 0);
Serial.println("OFF");
  }
 }
}
