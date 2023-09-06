#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#define BLYNK_TEMPLATE_ID "TMPLN4M0zwkF"
#define BLYNK_DEVICE_NAME "AB INITIO"
#define BLYNK_AUTH_TOKEN "dty_COTfDp5IwzZc9Le2pcDT0kohvnvj"
 
/* WiFi credentials */
char auth[] = "dty_COTfDp5IwzZc9Le2pcDT0kohvnvj";
char ssid[] = "nord";
char pass[] = "123456789";
 
SimpleTimer timer;
 
int mq135 = A0; // smoke sensor is connected with the analog pin A0 
int data = 0; 

void setup() 
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass,"blynk.cloud", 80);
  timer.setInterval(100L, getSendData); // new data will be updated every 1 sec 
}
 
void loop() 
{
  timer.run(); // Initiates SimpleTimer
  Blynk.run();
}
 
/***************************************************
 * Send Sensor data to Blynk      
 **************************************************/
void getSendData()
{
data = analogRead(mq135); 
  Blynk.virtualWrite(V2, data-100); //
}
