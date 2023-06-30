//Server Designing using TUNOIT
#include <WiFi.h>

String  Client_Request;
WiFiServer server(80);

void setup()
{
  Client_Request = "";

Serial.begin(9600);
  WiFi.disconnect();
  delay(3000);
   WiFi.begin("dlink","");
  Serial.println("Connecting to dlink");
  while ((!(WiFi.status() == WL_CONNECTED))){
    delay(300);
    Serial.print("");

  }
  Serial.println("Connected");
  Serial.print("Server IP");
  Serial.println((WiFi.localIP().toString()));
  server.begin();

}


void loop()
{

    WiFiClient client = server.available();
    if (!client) { return; }
    while(!client.available()){  delay(1); }
    Client_Request = (client.readStringUntil('\r'));
    Client_Request.remove(0, 5);
    Client_Request.remove(Client_Request.length()-9,9);
    Serial.println((client.remoteIP()));
    Serial.println(Client_Request);
    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("Welcome to Server.");
    client.println("</html>");

    delay(1);

}
