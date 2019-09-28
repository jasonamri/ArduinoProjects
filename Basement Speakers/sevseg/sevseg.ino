
#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment controller object

#include <DigiPotX9Cxxx.h>
DigiPot potl(17,16,15);
DigiPot potr(17,16,14);

void setup() {
  Serial.begin(115200);
  //7 segment display variables
  byte numDigits = 2;
  byte digitPins[] = {2, 3};
  byte segmentPins[] = {4, 5, 6, 7, 8, 9, 10, 11};
  bool resistorsOnSegments = false; // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_CATHODE; // See README.md for options
  bool updateWithDelays = false; // Default. Recommended
  bool leadingZeros = false; // Use 'true' if you'd like to keep the leading zeros
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros);
  sevseg.setBrightness(100);
}

void loop() {

long timer = millis();
  
  
  sevseg.refreshDisplay(); 


  Serial.println("Starting");  

  for (int i=0; i<100; i++) {
    Serial.print("Increasing, i = ");
    Serial.println(i, DEC);
    sevseg.setNumber(i);
    potl.increase(1);
    potr.increase(1);
    while(millis()<timer+200) {
      sevseg.refreshDisplay(); 
    }
    timer = millis();
  }

  for (int i=0; i<100; i++) {
    Serial.print("Decreasing, i = ");
    Serial.println(i, DEC);
    sevseg.setNumber(i);
    potl.decrease(1);
    potr.decrease(1);
    sevseg.refreshDisplay(); 
    while(millis()<timer+200) {
      sevseg.refreshDisplay(); 
    }
    timer = millis();
  }


}
