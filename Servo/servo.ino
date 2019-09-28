
#include <Servo.h> 
 
Servo myservo;  
int pos = 180;
int old = 198;
int cali = 0;
 
 
void setup() 
{ 
  myservo.attach(3);
pinMode(3, OUTPUT);  
  pos = pos + cali;
  myservo.write(pos);
  Serial.begin(9600);
} 
 
void loop() 
{    
  if (Serial.available() > 0) {
                pos = Serial.readString().toInt();
                pos = pos + cali;
              
               if (pos != old) {
                 pinMode(3, OUTPUT);
         myservo.write(pos);
         Serial.print(pos);
        Serial.print(" ");
        Serial.println(old);
                old = pos;
                delay(500);
                pinMode(3, INPUT);
       }
       
        }
       
} 
