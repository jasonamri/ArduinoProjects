int last = 0;
int count = 0;


void setup() {
  // put your setup code here, to run once:

pinMode(3,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,INPUT);
pinMode(13,OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

if (digitalRead(7) == HIGH && last == 0) {
  last = 1; 
  digitalWrite(13, HIGH);
}

if (digitalRead(7) == LOW && last == 1) {
  count++;
  last = 0;
   digitalWrite(13, LOW);
}


if (count > 12) {
 digitalWrite(3, HIGH);
}

if (count > 24) {
 digitalWrite(4, HIGH);
}

if (count > 36) {
 digitalWrite(5, HIGH);
}

if (count > 50) {
 digitalWrite(6, HIGH);
}

if (count > 55) {
  digitalWrite(6, LOW);
  delay(250);
  digitalWrite(5, LOW);
  delay(250);
  digitalWrite(4, LOW);
  delay(250);
  digitalWrite(3, LOW);
  count = 0;
  delay(350);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  delay(100);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  delay(100);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  delay(100);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  delay(100);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  delay(100);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  delay(100);
}

}
