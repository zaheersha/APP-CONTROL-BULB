#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

int bulb1=4;            //(any pin to esp8266)
int bulb2=3;           //(any pin to esp8266)
int bulb3=6;           //(any pin to esp8266)
int bulb4=7;            //(any pin to esp8266)

char ssid[] = "xxxxx";   // your network SSID (wifi hotspot name)
char pass[] = "xxxxx";   //wifi hotspot password

WiFiClient client;

unsigned long myChannelNumber = xxxxx; //channel id/number
const char * myWriteAPIKey = "xxxxx";     //my channal write key from API KEY

const char * myReadAPIKey = "xxxxx";     //my channal read key from API KEY

void setup() {
  // put your setup code here, to run once:
   pinMode(bulb1,OUTPUT);
   pinMode(bulb2,OUTPUT);
   pinMode(bulb3,OUTPUT);
   pinMode(bulb4,OUTPUT);
   WiFi.mode(WIFI_STA);
   ThingSpeak.begin(client);
   Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
   if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
   
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);    
    }
    Serial.println("\nConnected.");
  }
 
  ThingSpeak.setField(1, bulb1);         //(field,bulb)
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
  delay(20000);
   ThingSpeak.setField(2, bulb2);   //(field,bulb)
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
  delay(20000);
   ThingSpeak.setField(3, bulb3);          //(field,bulb)
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
  delay(20000);
   ThingSpeak.setField(4, bulb4);   //(field,bulb)
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
  delay(20000);

  float a = ThingSpeak.readFloatField(myChannelNumber, 1, myReadAPIKey);       //(myChannelNumber, field number, myReadAPIKey)
  Serial.println("ReadValue from ThingSpeak of the mobile app on/off : ");
  Serial.println(a);
  if (a > 0){
  digitalWrite(bulb1,HIGH);
 Serial.println("bulb1 IS ON : ");
  }
  else {
    digitalWrite(bulb1,LOW);
 Serial.println("bulb1 IS OFF: ");
  }
float b = ThingSpeak.readFloatField(myChannelNumber, 2, myReadAPIKey);       //(myChannelNumber, field number, myReadAPIKey)
  Serial.println("ReadValue from ThingSpeak of the mobile app on/off : ");
  Serial.println(b);
  if (b > 0){
  digitalWrite(bulb2,HIGH);
 Serial.println("bulb2 IS ON : ");
  }
  else {
    digitalWrite(bulb2,LOW);
 Serial.println("bulb2 IS OFF: ");
  }
float c = ThingSpeak.readFloatField(myChannelNumber, 3, myReadAPIKey);           //(myChannelNumber, field number, myReadAPIKey)
  Serial.println("ReadValue from ThingSpeak of the mobile app on/off : ");
  Serial.println(c);
  if (c > 0){
  digitalWrite(bulb3,HIGH);
 Serial.println("bulb3 IS ON : ");
  }
  else {
    digitalWrite(bulb3,LOW);
 Serial.println("bulb3 IS OFF: ");
  }
float d = ThingSpeak.readFloatField(myChannelNumber, 4, myReadAPIKey);           //(myChannelNumber, field number, myReadAPIKey)
  Serial.println("ReadValue from ThingSpeak of the mobile app on/off : ");
  Serial.println(d);
  if (d > 0){
  digitalWrite(bulb4,HIGH);
 Serial.println("bulb4 IS ON : ");
  }
  else {
    digitalWrite(bulb4,LOW);
 Serial.println("bulb4 IS OFF: ");
  }


   }