#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

int bulb1=4;            //(any pin to esp8266)


char ssid[] = "xxxxx";   // your network SSID (wifi hotspot name)
char pass[] = "xxxxx";   //wifi hotspot password

WiFiClient client;

unsigned long myChannelNumber = xxxxx; //channel id/number
const char * myWriteAPIKey = "xxxxx";     //my channal write key from API KEY

const char * myReadAPIKey = "xxxxx";     //my channal read key from API KEY

void setup() {
  // put your setup code here, to run once:
   pinMode(bulb1,OUTPUT);
 
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

   }