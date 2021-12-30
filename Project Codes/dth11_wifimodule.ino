#include <DHT.h>
#include <ESP8266WiFi.h>
#define DHTPIN 2
#define DHTTYPE DHT11
const char* ssid = "motupatlu";  
const char* password = "avi84650";
const char* writeAPIKey = "B92GU4AGWSTILD2Y";  
const char* host="api.thingspeak.com";
DHT dht(DHTPIN, DHTTYPE, 15);
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);  
dht.begin();
delay(1000);
Serial.println("Connecting to ");  
Serial.println(ssid); 
WiFi.begin(ssid, password);  
  while (WiFi.status() != WL_CONNECTED)  
  {  
delay(500);  
Serial.print(".");  
  } 
Serial.println("");  
Serial.println("WiFi connected"); 
}
void loop() {
  // put your main code here, to run repeatedly:
  float temperature = dht.readTemperature();
  float humidity=dht.readHumidity();
  if(isnan(temperature) || isnan(humidity)){
    return; 
  }
WiFiClient client;
const int httpPort = 80;
  if(!client.connect(host,httpPort)){
return ;
  }

  String url = "/update?key=";
url+=writeAPIKey;
url+="&field2=";
url+=String(temperature);
url+="&field3=";
url+=String(humidity);
url+="\r\n";
client.print(String("GET ") + url + " HTTP/1.1\r\n"+
               "Host : "+ host + "\r\n" +
               "Connection : close\r\n\r\n");
Serial.print(temperature);Serial.print(" *C, "); 
Serial.print(humidity);Serial.println(" H");
client.stop();
Serial.println(" ");
delay(1000);  
}
