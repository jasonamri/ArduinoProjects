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
char scene=1;
char oldscene=0;

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
  
}

void loop() {
  // put your main code here, to run repeatedly:
  uiPoll();
  delay(1);
  if(scene==1) {randomnLoop();}
  if(scene==2) {columnLoop();}
  if(scene==3) {microphoneLoop();}
  
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

  if(digitalRead(A5)==LOW) {scene=1;}
  if(digitalRead(A4)==LOW) {scene=2;}
  if(digitalRead(A3)==LOW) {scene=3;}

  if(oldscene!=scene) {
    if(scene==1) {randomnSetup();}
    if(scene==2) {columnSetup();}
    if(scene==3) {microphoneSetup();}
    oldscene=scene;
  }
  
}


void randomnSetup() {
  for(int i = 2; i < 5; i++) { SoftPWMSet(i, 0); }
  for(int j = 5; j < 14; j++) { SoftPWMSet(j, 0); }
  timer=millis();
}

void randomnLoop() {

  if(timer+spe<millis()) {
    SoftPWMSet(col1, 0);
    SoftPWMSet(row1, 0);
    col1=col0;
    row1=row0;
    SoftPWMSet(col1, bri);
    SoftPWMSet(row1, bri);
    while (col0 == col1 && row0 == row1) {
      col0 = random(2,5);
      row0 = random(5,14);
    }
    timer=millis();
  }
  
}

void columnSetup() {
  for(int i = 2; i < 5; i++) { SoftPWMSet(i, 255); }
  for(int j = 5; j < 14; j++) { SoftPWMSet(j, 0); }
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

void microphoneSetup() {
  for (int i=0; i <= 500; i++) {
    avg+=analogRead(A0);
    delay(1);
  }
  cal=avg/500;
  avg=0;
  for(int i = 2; i < 5; i++) { SoftPWMSet(i, 0); }
  for(int j = 5; j < 14; j++) { SoftPWMSet(j, 255); }
}

void microphoneLoop() {
  if(analogRead(A0)>=(cal+6)) {
    val=analogRead(A0)-cal-6;
  } else if(analogRead(A0)<=(cal-6)) {
    val=cal-6-analogRead(A0);  
  } else {
    val=0;
  }


  if(val==0) {
    SoftPWMSet(4, 0);
    SoftPWMSet(2, 0);
    SoftPWMSet(3, 0);
  }
  if(val>0&&val<15) {
    SoftPWMSet(4, val*17);
    SoftPWMSet(2, 0);
    SoftPWMSet(3, 0);
  }
  if (val>15&&val<30) {
    SoftPWMSet(4, 255);
    SoftPWMSet(2, (val-15)*17);
    SoftPWMSet(3, 0);
  }
  if (val>30&&val<45) {
    SoftPWMSet(4, 255);
    SoftPWMSet(2, 255);
    SoftPWMSet(3, (val-30)*17);
  }
  if (val>45) {
    SoftPWMSet(4, 255);
    SoftPWMSet(2, 255);
    SoftPWMSet(3, 255);
  } 
}
