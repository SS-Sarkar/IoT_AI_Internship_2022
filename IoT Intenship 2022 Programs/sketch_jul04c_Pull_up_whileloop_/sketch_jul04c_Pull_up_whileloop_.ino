#define led 22
#define push 23 
void setup() {
  // put your setup code here, to run once:
pinMode(push, INPUT);
pinMode(led, OUTPUT);
//Serial.begin(9600);
}
int pushData=0,count = 0;
void loop() {
  // put your main code here, to run repeatedly:
pushData = digitalRead(push); `
if(pushData == 0){
  while(pushData == 0){
    pushData = digitalRead(push);
  }
  count = count+1;
 // Serial.println(count);
}
 if(count == 1){
    digitalWrite(led ,HIGH);
  }
  else if(count == 2){
    digitalWrite(led ,LOW); 
    count =0; 
  }
}
