//libraries
#include <SoftPWM.h>
#include <SoftPWM_timer.h>

//column
const byte ledCol[] = {6,7,8,9,10,11,12,13};
byte led=0;

//randomn
int col0 = 2;
int row0 = 5;
int col1 = 2;
int row1 = 5;

//microphone
long avg=0;
int cal;
int val=0;

//globals
byte bri=255;
unsigned int spe=25;
unsigned long timer=millis();

void setup() {
  //global intialization
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT_PULLUP);
  pinMode(A4, INPUT_PULLUP);
  pinMode(A5, INPUT_PULLUP);
  SoftPWMBegin();
  for(int i = 2; i < 5; i++) { pinMode(i,OUTPUT); digitalWrite(i, LOW); }
  for(int j = 5; j < 14; j++) { pinMode(j, OUTPUT); digitalWrite(j, LOW); }

  columnSetup();

}

void loop() {
  // put your main code here, to run repeatedly:

  columnLoop();
  uiPoll();  
  delay(1);

}

void uiPoll() {
  //speed
  if((analogRead(A1)/2)!=spe&&(analogRead(A1)/2)>25&&(analogRead(A1)/2)<500) {
    spe=(analogRead(A1)/2);
  }
  
  //brightness
  if((analogRead(A2)/4)!=bri&&(analogRead(A2)/4)>=0&&(analogRead(A2)/4)<255) {
    bri=(analogRead(A2)/4);
  }
  
}

void columnSetup() {
  for(int i = 2; i < 5; i++) { digitalWrite(i, HIGH); }
  for(int j = 5; j < 14; j++) { digitalWrite(j, LOW); }
  timer=millis();
}

void columnLoop() {
  if(timer+spe<millis()) {

    led++;
  
    if(led==8) {led=0;}
    
    SoftPWMSet(ledCol[led], 0);
    
    if(led!=7) { SoftPWMSet(ledCol[led+1], bri);
    } else { SoftPWMSet(ledCol[0], bri); }

    timer=millis();
    
  }

  
}

