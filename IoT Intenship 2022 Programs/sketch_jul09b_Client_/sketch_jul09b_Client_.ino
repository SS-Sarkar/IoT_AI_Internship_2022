//Client design
#include <WiFi.h>
#include <HTTPClient.h>

String  Server_Ans;
String  httpurl;
String  TheHiddenAnswerOfClient;
HTTPClient http;

String SendWithAnswer(String IPcache, String monmessagecache) {
httpurl = "http://";
httpurl+=IPcache;
httpurl+="/";
httpurl+=monmessagecache;
http.begin(httpurl);
http.GET();
TheHiddenAnswerOfClient = (http.getString());
http.end();
return TheHiddenAnswerOfClient;
}

void setup()
{
  Server_Ans = "";

Serial.begin(9600);
  WiFi.disconnect();
  delay(3000);
  Serial.println("START");
   WiFi.begin("dlink","");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("");

  }
  Serial.println("Connected");
  Serial.println("Client IP");
  Serial.print((WiFi.localIP().toString()));

}


void loop()
{

    Server_Ans = (SendWithAnswer("192.168.28.46","lighton"));
    Server_Ans.remove(0, 25);
    Server_Ans.remove(Server_Ans.length()-11,11);
    Serial.println(Server_Ans);
    delay(5000);
    Server_Ans = (SendWithAnswer("192.168.28.46","lightoff"));
    Server_Ans.remove(0, 25);
    Server_Ans.remove(Server_Ans.length()-11,11);
    Serial.println(Server_Ans);
    delay(5000);

}
