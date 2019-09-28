//like damellis core

void setup() {
  for (byte x=1; x<=5; x++) {
    pinMode(x, INPUT_PULLUP);}

  pinMode(0, OUTPUT);
  digitalWrite(0, HIGH);

  for (byte x=6; x<=10; x++) {
    pinMode(x, OUTPUT);
    digitalWrite(x, LOW);}}
 
void loop() {
  for (byte x=1; x<=5; x++) { if (digitalRead(x)==LOW) change(x); delay(10);}
  }

void change(byte button) {
  byte pin;
  if (button==1) pin=7;  //VAR
  if (button==2) pin=6;  //-12v
  if (button==3) pin=9;  //12v
  if (button==4) pin=8;  //5v
  if (button==5) pin=10; //3.3v
  for (int x=6; x<=10; x++) { if (x!=pin) digitalWrite(x, LOW);}
  digitalWrite(0, LOW);
  digitalWrite(pin, !digitalRead(pin));
  while (digitalRead(button)==LOW) delay(10);
  }
