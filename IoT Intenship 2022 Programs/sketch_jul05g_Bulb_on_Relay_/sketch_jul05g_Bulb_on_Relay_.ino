//Turning a bulb on or off using RELAY
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
if(data == 'o'){
digitalWrite(23, 1);
Serial.println("Off");
}
else if(data == 'n'){
digitalWrite(23, 0);
Serial.println("On");
  }
 }
}
