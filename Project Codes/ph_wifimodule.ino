unsigned long int avgValue;  //Store the average value of the sensor feedback
float b;
int buf[10],temp;
#include <ESP8266WiFi.h>
const char* ssid = "motupatlu";  
const char* password = "avi84650";
const char* writeAPIKey = "B92GU4AGWSTILD2Y";  
const char* host="api.thingspeak.com";
void setup() {
Serial.begin(115200);
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
for(int i=0;i<10;i++)       //Get 10 sample value from the sensor for smooth the value
  { 
buf[i]=analogRead(A0);
delay(10);
  }
for(int i=0;i<9;i++)        //sort the analog from small to large
  {
for(int j=i+1;j<10;j++)
    {
      if(buf[i]>buf[j])
      {
        temp=buf[i];
buf[i]=buf[j];
buf[j]=temp;
      }
    }
  }


avgValue=0;
for(int i=2;i<8;i++)                      //take the average value of 6 center sample
  avgValue+=buf[i];
  float phValue=(float)avgValue*3.0/1024/6; //convert the analog into millivolt
  phValue=3.5*phValue;//convert the millivolt into pH value
String url = "/update?key=";
url+=writeAPIKey;
url+="&field1=";
url+=String(phValue);
url+="\r\n";
client.print(String("GET ") + url + " HTTP/1.1\r\n"+
               "Host : "+ host + "\r\n" +
               "Connection : close\r\n\r\n");
Serial.println(phValue);
client.stop();
Serial.println(" ");
delay(1000);  
}
