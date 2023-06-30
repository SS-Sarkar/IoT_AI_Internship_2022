#define led 22
#define push 23
void setup() {
  // put your setup code here, to run once:
pinMode(push, INPUT);
pinMode(led, OUTPUT);
}
int pushData=0;
void loop() {
  // put your main code here, to run repeatedly:
pushData = digitalRead(push);
if(pushData == 0){
  //Led ON
  digitalWrite(led ,HIGH);
}
else if(pushData == 1){
 //Led OFF
 digitalWrite(led ,LOW); 
}
}
