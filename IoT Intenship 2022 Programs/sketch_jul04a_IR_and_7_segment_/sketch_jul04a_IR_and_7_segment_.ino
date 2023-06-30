#define a 22
#define b 21
#define c 19
#define d 18
#define e 17
#define f 16
#define g 15
#define push 23
void setup() {
  // put your setup code here, 
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
}
  int  pushData =0;
  int i=0;
            
void loop() {
  // put your main code here, to run repeatedly:
  pushData = digitalRead(push);
  
  if (pushData == 0){ 
    while(pushData == 0){
      pushData =digitalRead(push);
     delay(2);
    }
    i=i+1;
    
   }
  if ( i == 0){
    digitalWrite(a,1);
    digitalWrite(b,1);    
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,0);
  }
  else if(i==1){
 digitalWrite(a,0);
 digitalWrite(b,1);    
  digitalWrite(c,1);
  digitalWrite(d,0);
 digitalWrite(e,0);
 digitalWrite(f,0);
  digitalWrite(g,0);
  }
  else if(i==2){   
 digitalWrite(a,1);
 digitalWrite(b,1);    
  digitalWrite(c,0);
  digitalWrite(d,1);
 digitalWrite(e,1);
 digitalWrite(f,0);
  digitalWrite(g,1);
  }
  else if(i==3){
   digitalWrite(a,1);
 digitalWrite(b,1);    
  digitalWrite(c,1);
  digitalWrite(d,1);
 digitalWrite(e,0);
 digitalWrite(f,0);
  digitalWrite(g,1);
  }
  else if(i==4){
    digitalWrite(a,0);
 digitalWrite(b,1);    
  digitalWrite(c,1);
  digitalWrite(d,0);
 digitalWrite(e,0);
 digitalWrite(f,1);
  digitalWrite(g,1);
  }
  else if(i==5){
   digitalWrite(a,1);
 digitalWrite(b,0);    
  digitalWrite(c,1);
  digitalWrite(d,1);
 digitalWrite(e,0);
 digitalWrite(f,1);
  digitalWrite(g,1);
  }
  else if(i==6){
   digitalWrite(a,1);
 digitalWrite(b,0);    
  digitalWrite(c,1);
  digitalWrite(d,1);
 digitalWrite(e,1);
 digitalWrite(f,1);
  digitalWrite(g,1);
  }
  else if(i==7){
   digitalWrite(a,1);
 digitalWrite(b,1);    
  digitalWrite(c,1);
  digitalWrite(d,0);
 digitalWrite(e,0);
 digitalWrite(f,0);
  digitalWrite(g,0);
  }
  else if(i==8){
    digitalWrite(a,1);
 digitalWrite(b,1);    
  digitalWrite(c,1);
  digitalWrite(d,1);
 digitalWrite(e,1);
 digitalWrite(f,1);
  digitalWrite(g,1);
  }
   else if(i==9){
    digitalWrite(a,1);
 digitalWrite(b,1);    
  digitalWrite(c,1);
  digitalWrite(d,1);
 digitalWrite(e,0);
 digitalWrite(f,1);
  digitalWrite(g,1);
   }
   else if(i == 10){
    i =0;
   }
   }
