
#include <IRremote.h>



IRrecv irrecv(12);

decode_results results;

int time1 = 25;
int time2 = 100;
int state = 1;

void setup() {
  
irrecv.enableIRIn();

}

void loop() {
  
  for (int pin = 2 ; pin <= 11; pin += 1) {
    // sets the value (range from 0 to 255):
    check();
    
    
    if (state == 1) {
      
    digitalWrite(pin+1, HIGH);
    digitalWrite(pin, HIGH);
    digitalWrite(pin-1, HIGH);
    digitalWrite(pin-2, LOW);
    
    
    if (pin==10 || pin==11) {
      delay(time1);
    } else {
      delay(time2);
    }
    
    
  } else {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    
  }
  
  }

 
  for (int pin = 11 ; pin >= 2; pin -= 1) {
    // sets the value (range from 0 to 255):
    check();
    
    
     if (state == 1) {
    
    digitalWrite(pin+2, LOW);
    digitalWrite(pin+1, HIGH);
    digitalWrite(pin, HIGH);
    digitalWrite(pin-1, HIGH);

    if (pin==3 || pin==2) {
      delay(time1);
    } else {
      delay(time2);
    }
    
  } else {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    
  }
    
  }




}


void check() {
  if (irrecv.decode(&results)) {
    
    if (results.value==0x22D912BB) {
      time2 = time2 + 12.5;
    }
    
    if (results.value==0x776C6E7A) {
      time2 = time2 - 12.5;
    }
    
    if (results.value==0xC3E3EA16) {
      time1 = time1 + 12.5;
    }
    
    if (results.value==0x656BA055) {
      time1 = time1 - 12.5;
    }
    
    if (results.value==0x78F9D2FD) {
      if (state==1) {
        state=0;
      } else {
        state=1;
      } 
    }
    
    if (results.value==0x7F6406E6) {  // Slow-Mo
      time1 = 75;
      time2 = 300;
    }
    
    if (results.value==0x92DFD41F) { // Regular
      time1 = 25;
      time2 = 100;
    }
    
    if (results.value==0xDABC35D) { // Low Power
      time1 = 500;
      time2 = 500;
    }
    
    
    irrecv.resume(); // Receive the next value
  }
}
