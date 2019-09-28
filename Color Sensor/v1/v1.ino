
        int redValue = 132;
	int greenValue = 50;
	int blueValue = 65;
        int red = 0;
	int green = 0;
	int blue = 0;

#include <Servo.h> 
 
Servo myservo;  
int pos = 160;
int old = 160;


void setup()
{
  pinMode(3, OUTPUT);
  myservo.attach(3);  
  pos = pos;
  myservo.write(pos);
	pinMode(8, OUTPUT);
	pinMode(7, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(13, OUTPUT);
	digitalWrite(8, HIGH);
	digitalWrite(7, HIGH);
	digitalWrite(6, HIGH);
	pinMode(3, INPUT);
	Serial.begin(9600);
}

void loop()
{
	delay(50);
	digitalWrite(8, LOW);
	delay(25);
	red = analogRead(1);
	delay(25);
	digitalWrite(8, HIGH);
	
	delay(50);
	digitalWrite(7, LOW);
	delay(25);
	green = analogRead(1);
	delay(25);
	digitalWrite(7, HIGH);
	
	delay(50);
	digitalWrite(6, LOW);
	delay(25);
	blue = analogRead(1);
	delay(25);
	digitalWrite(6, HIGH);
	
	Serial.print(red);
	Serial.print(" ");
	Serial.print(green);
	Serial.print(" ");
	Serial.println(blue);
	
	if (red < redValue + 25 && red > redValue - 25 && green < greenValue + 10 && green > greenValue - 10 && blue < blueValue + 10 && blue > blueValue - 10) {
          pos = 20;
          Serial.println("good");
       } else {
	  pos = 160;
       }
       
       
       if(pos!=old) {
         pinMode(3, OUTPUT);
         myservo.write(pos);
         old = pos;
         delay(500);
         pinMode(3, INPUT);
       }
                 
      if (pos==20) {
       delay(5000); 
      }
}
