void setup()
{
  Serial.begin(9600);
}

void loop()
{
 
  Serial.print('H'); 
  Serial.print(",");
  Serial.print(analogRead(0));
  Serial.print(",");
  Serial.print(analogRead (1));
  Serial.print(",");
  Serial.print(analogRead (2));
  Serial.print(",");  
  Serial.println(); 
  delay(1);
}
