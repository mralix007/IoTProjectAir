void setup()

{
pinMode(A1,INPUT);
Serial.begin(9600);
}
void loop()
{
int sv=analogRead(A1);
Serial.print("AQI=");
Serial.print(sv);
Serial.print("ppm");
delay (400);
Serial.println(" ");
}