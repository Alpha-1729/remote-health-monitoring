#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>

 
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "anditsallbecause";
 
// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "hotspotname";
char pass[] = "password";
#define sensorPin  A0
BlynkTimer timer;
 
// This function sends Arduino's up time every second to Virtual Pin (5).
// In the app, Widget's reading frequency should be set to PUSH. This means
// that you define how often to send data to Blynk App.
void sendSensor()
{
 int reading = analogRead(sensorPin);
 float voltage = (reading * 5.0)/1024;
 float temperatureC = voltage * 100 ;
  
  
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V1, temperatureC);
}
 
void setup()
{
  // Debug console
  Serial.begin(9600);
 
  Blynk.begin(auth, ssid, pass);
 
  // Setup a function to be called every second
  timer.setInterval(1000L, sendSensor);
}
 
void loop()
{
  Blynk.run();
  timer.run();
}
