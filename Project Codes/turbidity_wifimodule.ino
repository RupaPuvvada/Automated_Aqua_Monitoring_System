int turbidity;
#include <ESP8266WiFi.h>
const char* ssid = "motupatlu";  
const char* password = "avi84650";
const char* writeAPIKey = "B92GU4AGWSTILD2Y";  
const char* host="api.thingspeak.com";
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);  
pinMode(A0,INPUT);
Serial.println("Connecting to ");  
Serial.println(ssid); 
WiFi.begin(ssid, password);  
  while (WiFi.status() != WL_CONNECTED)  
  {  
delay(300);  
Serial.print(".");  
  } 
Serial.println("");  
Serial.println("WiFi connected"); 
}
void loop() {
  // put your main code here, to run repeatedly:
  
WiFiClient client;
const int httpPort = 80;
  if(!client.connect(host,httpPort)){
return ;
  }
  turbidity=analogRead(A0);
  float volt=turbidity*(3.0/1024.0)*3;

  String url = "/update?key=";
url+=writeAPIKey;
url+="&field4=";
url+=String(volt);
url+="\r\n";
client.print(String("GET ") + url + " HTTP/1.1\r\n"+
               "Host : "+ host + "\r\n" +
               "Connection : close\r\n\r\n");
Serial.println(volt);
client.stop();
Serial.println(" ");
delay(1000);  
}
