#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

#define TXpin 5
#define RXpin 4

TinyGPSPlus gps;
SoftwareSerial SerialGPS(RXpin, TXpin); 

WiFiServer server(80);
void setup()
{
  Serial.begin(9600);
  SerialGPS.begin(9600);
}

void loop()
{
   //SerialGPS.write("12345\r\n");
   //Serial.println(SerialGPS.available());
   String str = "";
   if(SerialGPS.available() > 0 ) {
   while(SerialGPS.available() > 0 ) {
    str = str + (char)SerialGPS.read();
   }
   Serial.println(str);
   }
   delay(1000);
}
