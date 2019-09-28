//Countdown Variables --
unsigned long Watch, _micro, time = micros();
unsigned int Clock = 0, R_clock;
boolean Reset = false, Stop = false, Paused = false;
volatile boolean timeFlag = false;
//--

//My Code --
#include <LedControl.h>
LedControl lc=LedControl(2,0,1,1);

int debounce=50;
unsigned long duration = 1000000; // 1 second
int digit1;
int digit2;
int digit3;
int digit4;
int inputState=0;
int lastState1=0;
int lastState2=0;
int lastState3=0;
unsigned long input1=0;
unsigned long input2=0;
unsigned long input3=0;
int down=3;
int up=4;
int t1=0;
int t2=0;
int t3=0;
int t4=0;
int d1=0;
int d2=0;
int d3=0;
int d4=0;
int timer=610;



void setup()
{
  
  
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);

  SetTimer(timer);
  StartTimer();

  pinMode(down, INPUT_PULLUP);
  pinMode(up, INPUT_PULLUP);

  
}



void loop()
{
  if(inputState==0) {
  CountDownTimer(); 
  output();
  } 
  input();
  delay(25);
}





void output()
{if (TimeHasChanged()){

  //parse digits --
  //digit 1
  if (ShowMinutes()<10) {
    
    lc.setChar(0,0,' ',false);
  } else {
    digit1 = (ShowMinutes() - (ShowMinutes() % 10)) / 10;
    lc.setDigit(0,0,digit1,false);
  }
  
  //digit 2
  if (ShowMinutes()!=0) {
    digit2 = ShowMinutes() % 10;
  } else {
    digit2 = 0;
  }
  
  //digit 3
  if (ShowSeconds()<10) {
    digit3 = 0;
  } else {
    digit3 = (ShowSeconds() - (ShowSeconds() % 10)) / 10;
  }
  
  //digit 4
  if (ShowSeconds()!=0) {
    digit4 = ShowSeconds() % 10;
  } else {
    digit4 = 0;
  }
  //-- parse digits  





  //display --
    //digit one has been move up in order
    //to remove 0 (eg. 01:23 becomes 1:23)
    lc.setDigit(0,1,digit2,false);
    lc.setDigit(0,2,digit3,false);
    lc.setDigit(0,3,digit4,false);
    lc.setRow(0,4,B01100000);
  //-- dislay

  
}}






void input()
{
  //waiting for a button to be held
  if(inputState==0) {
    
  
    //if up button is pressed
    if(digitalRead(up)==LOW) {

      //if this isn't the first time the button was pressed and it has been for 1s 
      if(input1+2500<millis()&&lastState1==1) {
        //display screen for inputState1
        inputState=1;
        display1();
      }

      //if this is the first time the button is pressed, then restart the hold counter
      if (lastState1==0) {
        input1=millis();
        //update state
        lastState1=1;
      }
    } else {
      lastState1=0;
    }

    //if down button is pressed
    if(digitalRead(down)==LOW) {

      //if this isn't the first time the button was pressed and it has been for 1s 
      if(input2+2500<millis()&&lastState2==1) {
        //display screen for inputState1
        inputState=2;
        display2();
      }

      //if this is the first time the button is pressed, then restart the hold counter
      if (lastState2==0) {
        input2=millis();
        //update state
        lastState2=1;
      }
    } else {
      lastState2=0;
    }

  }






  if(inputState==1) {
    if(digitalRead(up)==LOW && digitalRead(down)==LOW) {
      lc.setRow(0,4,B01100000);
      delay(1000);
      SetTimer(timer);
      StartTimer();
      inputState=0;
    }
    if(digitalRead(up)==LOW && digitalRead(down)!=LOW) {
      timer++;
      display1();
      delay(debounce);
    }
    if(digitalRead(up)!=LOW && digitalRead(down)==LOW) {
      timer--;
      display1();
      delay(debounce);
    }
        //if any button is pressed
    if(digitalRead(up)==LOW||digitalRead(down)==LOW) {

      //if this isn't the first time the button was pressed and it has been for 1s 
      if(input3+1000<millis()&&lastState3==1) {
        //display screen for inputState1
        debounce=10;
      }

      //if this is the first time the button is pressed, then restart the hold counter
      if (lastState3==0) {
        input3=millis();
        //update state
        lastState3=1;
      }
    } else {
      lastState3=0;
      debounce=50;
    }

    
  }









  if(inputState==2) {
    if(digitalRead(up)==LOW && digitalRead(down)==LOW) {
      lc.setRow(0,4,B01100000);
      delay(1000);
      SetTimer(timer);
      StartTimer();
      inputState=0;
    }
    if(digitalRead(up)==LOW && digitalRead(down)!=LOW) {
      duration=duration+1000;
      display2();
      delay(debounce);
    }
    if(digitalRead(up)!=LOW && digitalRead(down)==LOW) {
      duration=duration-1000;
      display2();
      delay(debounce);
    }
        //if any button is pressed
    if(digitalRead(up)==LOW||digitalRead(down)==LOW) {

      //if this isn't the first time the button was pressed and it has been for 1s 
      if(input3+1000<millis()&&lastState3==1) {
        //display screen for inputState1
        debounce=10;
      }

      //if this is the first time the button is pressed, then restart the hold counter
      if (lastState3==0) {
        input3=millis();
        //update state
        lastState3=1;
      }
    } else {
      lastState3=0;
      debounce=50;
    }
  }






  
}







void display1 () {
  //parse the timer int
  t1=(timer-(timer%1000))/1000;
  t2=((timer-(timer%100))/100)%10;
  t3=((timer-(timer%10))/10)%10;
  t4=timer%10;

  //display it
  lc.setDigit(0,0,t1,false);
  lc.setDigit(0,1,t2,false);
  lc.setDigit(0,2,t3,false);
  lc.setDigit(0,3,t4,false);
  lc.setRow(0,4,B00000000);
}

void display2 () {
  d1=(duration-(duration%1000000))/1000000;
  d2=((duration-(duration%100000))/100000)%10;
  d3=((duration-(duration%10000))/10000)%10;
  d4=((duration-(duration%1000))/1000)%10;

  //display it
  lc.setDigit(0,0,d1,false);
  lc.setDigit(0,1,d2,false);
  lc.setDigit(0,2,d3,true);
  lc.setDigit(0,3,d4,false);
  lc.setRow(0,4,B00000000);
}
















//Library for Countdown --
boolean CountDownTimer()
{
  
  timeFlag = false;

  if (!Stop && !Paused) // if not Stopped or Paused, run timer
  {
    // check the time difference and see if 1 second has elapsed
    if ((_micro = micros()) - time > duration )
    {
      Clock--;
      timeFlag = true;

      if (Clock == 0) // check to see if the clock is 0
        Stop = true; // If so, stop the timer

      // check to see if micros() has rolled over, if not,
      // then increment "time" by duration
      _micro < time ? time = _micro : time += duration;
    }
  }
  return !Stop; // return the state of the timer
}

void ResetTimer()
{
  SetTimer(R_clock);
  Stop = false;
}

void StartTimer()
{
  Watch = micros(); // get the initial microseconds at the start of the timer
  Stop = false;
  Paused = false;
}

void StopTimer()
{
  Stop = true;
}

void StopTimerAt(unsigned int hours, unsigned int minutes, unsigned int seconds)
{
  if (TimeCheck(hours, minutes, seconds) )
    Stop = true;
}

void PauseTimer()
{
  Paused = true;
}

void ResumeTimer() // You can resume the timer if you ever stop it.
{
  Paused = false;
}

void SetTimer(unsigned int hours, unsigned int minutes, unsigned int seconds)
{
  // This handles invalid time overflow ie 1(H), 0(M), 120(S) -> 1, 2, 0
  unsigned int _S = (seconds / 60), _M = (minutes / 60);
  if (_S) minutes += _S;
  if (_M) hours += _M;

  Clock = (hours * 3600) + (minutes * 60) + (seconds % 60);
  R_clock = Clock;
  Stop = false;
}

void SetTimer(unsigned int seconds)
{
  // StartTimer(seconds / 3600, (seconds / 3600) / 60, seconds % 60);
  Clock = seconds;
  R_clock = Clock;
  Stop = false;
}

int ShowHours()
{
  return Clock / 3600;
}

int ShowMinutes()
{
  return (Clock / 60) % 60;
}

int ShowSeconds()
{
  return Clock % 60;
}

unsigned long ShowMilliSeconds()
{
  return (_micro - Watch) / 1000.0;
}

unsigned long ShowMicroSeconds()
{
  return _micro - Watch;
}

boolean TimeHasChanged()
{
  return timeFlag;
}

// output true if timer equals requested time
boolean TimeCheck(unsigned int hours, unsigned int minutes, unsigned int seconds)
{
  return (hours == ShowHours() && minutes == ShowMinutes() && seconds == ShowSeconds());
}
//--
