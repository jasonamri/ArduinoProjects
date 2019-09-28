#include <IRremote.h>

int select = 1;



int 1state = 0;

int 1redValue = 0;
int 1greenValue = 0;
int 1blueValue = 0;

int 1redPin = 9;
int 1bluePin = 10;
int 1greenPin = 10;




int 2state = 0;

int 2redValue = 0;
int 2greenValue = 0;
int 2blueValue = 0;

int 2redPin = 9;
int 2bluePin = 10;
int 2greenPin = 10;




IRrecv irrecv(12);
decode_results results;

void setup() {
  irrecv.enableIRIn();
  
  pinMode(1redValue, OUTPUT);
  pinMode(1blueValue, OUTPUT);
  pinMode(1greenPin, OUTPUT);
  
  pinMode(2redPin, OUTPUT);
  pinMode(2bluePin, OUTPUT);
  pinMode(2greenPin, OUTPUT);
  
  Serial.begin(9600);
  
}

void loop() {
if (irrecv.decode(&results)) {

  
  
  
  if (select==1) {
    if (results.value==0xE0E020DF && 1state==1) {
     up(1redPin, 1redValue);
    }
    if (results.value==0xE0E010EF && 1state==1) {
     down(1redPin, 1redValue);
    } 
   
   if (results.value==0xE0E0A05F && 1state==1) {
     up(1bluePin, 1blueValue);
    }
    if (results.value==0xE0E0906F && 1state==1) {
     down(1bluePin, 1blueValue);
    } 
    
    if (results.value==0xE0E0609F && 1state==1) {
     up(1greenPin, 1greenValue);
    }
    if (results.value==0xE0E050AF && 1state==1) {
     down(1greenPin, 1greenValue);
    } 
  }
  
  
  
  
  
  if (select==2) {
    if (results.value==0xE0E020DF && 2state==1) {
     up(2redPin, 2redValue);
    }
    if (results.value==0xE0E010EF && 2state==1) {
     down(2redPin, 2redValue);
    } 
   
   if (results.value==0xE0E0A05F && 2state==1) {
     up(2bluePin, 2blueValue);
    }
    if (results.value==0xE0E0906F && 2state==1) {
     down(2bluePin, 2blueValue);
    } 
    
    if (results.value==0xE0E0609F && 2state==1) {
     up(2greenPin, 2greenValue);
    }
    if (results.value==0xE0E050AF && 2state==1) {
     down(2greenPin, 2greenValue);
    } 
  }
  
  
  
  
  
 if (select==3) {
   
     if (results.value==0xE0E020DF && 1state==1) {
     up(1redPin, 1redValue);
    }
    if (results.value==0xE0E010EF && 1state==1) {
     down(1redPin, 1redValue);
    } 
   
   if (results.value==0xE0E0A05F && 1state==1) {
     up(1bluePin, 1blueValue);
    }
    if (results.value==0xE0E0906F && 1state==1) {
     down(1bluePin, 1blueValue);
    } 
    
    if (results.value==0xE0E0609F && 1state==1) {
     up(1greenPin, 1greenValue);
    }
    if (results.value==0xE0E050AF && 1state==1) {
     down(1greenPin, 1greenValue);
    } 
    
    
    
    
    if (results.value==0xE0E020DF && 2state==1) {
     up(2redPin, 2redValue);
    }
    if (results.value==0xE0E010EF && 2state==1) {
     down(2redPin, 2redValue);
    } 
   
   if (results.value==0xE0E0A05F && 2state==1) {
     up(2bluePin, 2blueValue);
    }
    if (results.value==0xE0E0906F && 2state==1) {
     down(2bluePin, 2blueValue);
    } 
    
    if (results.value==0xE0E0609F && 2state==1) {
     up(2greenPin, 2greenValue);
    }
    if (results.value==0xE0E050AF && 2state==1) {
     down(2greenPin, 2greenValue);
    }
    
  }
  
  
   if (results.value==0xE0E030CF) {
     select=1
   }
   if (results.value==0xE0E0B04F) {
     select=3
   }
  if (results.value==0xE0E0708F) {
     select=2
   }
   
   
   
   
  
 
 


  
  irrecv.resume();
}
}


void up(int pin, int val) {
  if(val>249){ 
      analogWrite(pin,val);
  } else {
      val = val + 25;
      analogWrite(pin,val);
  }
  delay(250);
}

void down(int pin, int val) {
  if(redValue < 25){ 
      analogWrite(pin,val);
  } else {
      val = val - 25;
      analogWrite(pin,val);
  }
  delay(250); 
}
