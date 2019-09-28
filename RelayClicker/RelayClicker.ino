unsigned long int timer = 0;
unsigned long int ontime = 0;
unsigned long int offtime = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(6, OUTPUT);

Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:

  

  
  digitalWrite(6, HIGH);
  timer = millis();
  while(analogRead(0)<1000){}
  ontime = millis() - timer;

  
  digitalWrite(6, LOW);
  timer = millis();
  while(analogRead(0)>25){}
  offtime = millis() - timer;

  Serial.print(ontime);
  Serial.print("  ");
  Serial.println(offtime);


}
