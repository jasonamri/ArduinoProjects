//libraries
#include <MovingAverageFilter.h>

//library objects for each channel
MovingAverageFilter MA1(1000);
MovingAverageFilter MA2(1000);
MovingAverageFilter MA3(1000);
MovingAverageFilter MA4(1000);



//global variables for each channels
float cal1 = 0;
float average1 = 0;
int multi1 = 0;

float cal2 = 0;
float average2 = 0;
int multi2 = 0;

float cal3 = 0;
float average3 = 0;
int multi3 = 0;

float cal4 = 0;
float average4 = 0;
int multi4 = 0;

void setup() {
  Serial.begin(9600); 
}

void loop() {

//take readings
  average1 = (MA1.process(analogRead(1))*multi1) - cal1;
  average2 = (MA2.process(analogRead(2))*multi2) - cal2;
  average3 = (MA3.process(analogRead(3))*multi3) - cal3;
  average4 = (MA4.process(analogRead(4))*multi4) - cal4;



//calibrate after 5s
  if (millis() > 5000 && millis() < 5200) {
    calibrate1();
    calibrate2();
    calibrate3();
    calibrate4();
  }



//display averages if over 0
  if(average1>0) {
    Serial.print(average1);
    Serial.print("     ");
  }
  if(average2>0) {
    Serial.print(average2);
    Serial.print("     ");
  }
  if(average3>0) {
    Serial.print(average3);
    Serial.print("     ");
  }
  if(average4>0) {
    Serial.print(average4);
    Serial.print("     ");
  }
    Serial.println("     ");



// delay in between reads better averages
  delay(50);        
}



//calibrate
void calibrate1 () { cal1 = (MA1.process(analogRead(1))*multi1); }
void calibrate2 () { cal2 = (MA2.process(analogRead(2))*multi2); }
void calibrate3 () { cal3 = (MA3.process(analogRead(3))*multi3); }
void calibrate4 () { cal4 = (MA4.process(analogRead(4))*multi4); }

