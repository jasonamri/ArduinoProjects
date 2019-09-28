//radio
#include <ar1010lib.h>
#include <Wire.h>
AR1010 radio = AR1010();

//sleep
#include <avr/interrupt.h>
#include <avr/power.h>
#include <avr/sleep.h>
#include <avr/io.h>

//sev seg
#include <SevSeg.h>
SevSeg sevseg;
byte numDigits = 2;
byte digitPins[] = {12, 13};
byte segmentPins[] = {4, 5, 6, 7, 8, 9, 10, 11};
bool resistorsOnSegments = true;
byte hardwareConfig = COMMON_CATHODE;
bool updateWithDelays = false;
bool leadingZeros = true; 

//digital pots
#include <DigiPotX9Cxxx.h>
DigiPot potl(17,16,15);
DigiPot potr(17,16,14);

//ir remote
#include <IRremote.h>
IRrecv irrecv(2);
decode_results results;

//display persistence
#include <EEPROM.h>
bool visible;

//global
byte upLimit = 100;
byte downLimit = 0;
byte volume = 0;
byte oldVolume = 100;
byte XCvolume = 0;
bool muted = 0;
long timer = 0;

void setup() {


  
  
  //radio
  delay(100);
  Wire.begin();
  radio.initialise();
  delay(2500);
  radio.setFrequency(999);
  radio.setVolume(18);

  //sev seg
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros);
  sevseg.setBrightness(100);   //not stricly nessecary, set to 100 by default

  //ir remote
  irrecv.enableIRIn();


  //persistent display settings
  visible = EEPROM.read(0);


  //update display and volume for good measure
  updater();


}

void loop() {

    //refresh display
    refresh();

}

void wakeup() {
}

void refresh() {

  if(visible) {
    
  
    sevseg.refreshDisplay();

  

  } else {
    
    sevseg.blank();
   
  }
  
  input();
  
}

void input() {
if (irrecv.decode(&results)) {
         if (results.value == 3772793023) power();
    else if (results.value == 3772833823) up();
    else if (results.value == 3772829743) down();
    else if (results.value == 3772837903) mute();
    else if (results.value == 3772790473) a();
    else if (results.value == 3772786903) b();
    else if (results.value == 3772819543) c();
    else if (results.value == 3772803223) d();
    else if (results.value == 3772801693) visibility();
    //Serial.println(results.value);
    irrecv.resume(); // Receive the next value
    
  }
}

void updater() {
  XCvolume = map(volume, 0, 100, downLimit, upLimit);
  sevseg.setNumber(XCvolume);
  while (XCvolume > oldVolume) {
    potl.increase(1);
    potr.increase(1);
    oldVolume++;}
  while (XCvolume < oldVolume) {
    potl.decrease(1);
    potr.decrease(1);
    oldVolume--;}
    
}

void power() {

    //blank display
    sevseg.blank();

    //mute
    XCvolume=0;
    while (XCvolume > oldVolume) {
      potl.increase(1);
      potr.increase(1);
      oldVolume++;}
    while (XCvolume < oldVolume) {
      potl.decrease(1);
      potr.decrease(1);
      oldVolume--;}

    //blank display
    sevseg.blank();

    //debounce
    delay(500);

    //blank display
    sevseg.blank();
    
    //setup wake interupt
    attachInterrupt(0,wakeup,FALLING);

    // Choose our preferred sleep mode:
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
 
    // Set sleep enable (SE) bit:
    sleep_enable();

    // Put the device to sleep:
    sleep_mode();
 
    // Upon waking up, sketch continues from this point.
    sleep_disable();

    //detach to prevent a repeat interupt
    detachInterrupt(0);

    //upate display and restore volume
    updater();

    //debounce
    delay(200);
}

void up() {
  if (volume < 100) {volume++;}
  updater();
}

void down() {
  if (volume > 0) {volume--;}
  updater();
}

void mute() {
  muted = !muted;
  if (muted==0) {
    sevseg.setNumber(100);
    XCvolume=0;
  while (XCvolume > oldVolume) {
    potl.increase(1);
    potr.increase(1);
    oldVolume++;}
  while (XCvolume < oldVolume) {
    potl.decrease(1);
    potr.decrease(1);
    oldVolume--;}
  } else {
    updater();
  }
  delay(200);
}

void c() {
  if (downLimit < 100) {downLimit++;}
  updater();
}

void d() {
  if (downLimit > 0) {downLimit--;}
  updater();
}

void a() {
  if (upLimit < 100) {upLimit++;}
  updater();
}

void b() {
  if (upLimit > 0) {upLimit--;}
  updater();
}

void visibility() {

  visible = !visible;
  EEPROM.write(0, visible);
  updater();
  delay(200);

}


