#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

BlynkTimer timer;

char auth[] = "dty_COTfDp5IwzZc9Le2pcDT0kohvnvj";   //enter your token from email
char ssid[] = "nord";                              //enter your wifi username
char pass[] = "123456789";                          //enter your wifi password

const int BUZ = 5;  //buzzer to nodemcu D1 (GPIO-5)
const int LED = 4;  //LED to nodemcu D2 (GPIO-4)
int mq135 = A0;     //smoke sensor is connected with the analog pin A0
int data = 0;

void sensorData()
{
  data = analogRead(mq135);           //read A0 pin of NodeMCU
  Blynk.virtualWrite(V2,data);        //virtual pin V2
  
  if (data > 800)                     //trigger buzzer if if smoke sensor value is greate than 400
  {
      tone(BUZ,1000);                   // Send 1KHz sound signal…
      delay(500);
      digitalWrite(LED,HIGH);
      delay(500);                      // …for 1 sec
  }
  else
  {
    digitalWrite(LED,LOW);
    digitalWrite(BUZ,LOW);
  }
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass,"blynk.cloud", 80);  //PING blynk-cloud.com
  timer.setInterval(100L, sensorData);
  pinMode(BUZ, OUTPUT); // Set BUZ 
  pinMode(LED, OUTPUT); // Set LED 
}

void loop() {
  Blynk.run();
  timer.run();
}
