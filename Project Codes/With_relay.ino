#include <SimpleDHT.h>
int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);
unsigned long int avgValue;  //Store the average value of the sensor feedback
float b;
int buf[10],temp;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.println("READY ");
//Serial.print("PH");Serial.print("\t");
  Serial.print("Temperature");Serial.print("&");Serial.print("Humidity");Serial.print("\t");
  Serial.println("Turbidity");
pinMode(A0,INPUT);
pinMode(A3,INPUT);
pinMode(7,OUTPUT);
//pinMode(3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
   int turbidity = analogRead(A3);
  float volt=turbidity*(5.0/1024.0)*3-4;
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
for(int i=2;i<8;i++)  
{
  //take the average value of 6 center sample
avgValue+=buf[i];
}
  float phValue=(float)avgValue*5.0/1024/6; //convert the analog into millivolt
phValue=3.5*phValue-3;                      //convert the millivolt into pH value 
    byte t = 0;
     byte h = 0;
int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&t, &h, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.print(SimpleDHTErrCode(err));
    Serial.print(","); Serial.println(SimpleDHTErrDuration(err)); delay(1000);
    return;
  } 
  Serial.print(phValue);Serial.print("\t");  
Serial.print(t);Serial.print(" *C ");Serial.print("     & ");Serial.print("    ");Serial.print(h);Serial.print(" H ");Serial.print("\t");
Serial.println(volt);
  if(volt>2.8){
digitalWrite(7,HIGH);
  }
  else
  {
digitalWrite(7,LOW);
  }
if(phValue>10 && phValue<4){
digitalWrite(7,HIGH);
  }
  else
  {
digitalWrite(7,LOW);
  }
if(t<20 && t>60){
digitalWrite(7,HIGH);
  }
  else
  {
digitalWrite(7,LOW);
  }
delay(1000);
}
