#include <IRremote.h>
int state = 0;
int redValue = 0;
int greenValue = 0;
int blueValue = 0;

IRrecv irrecv(12);
decode_results results;

void setup() {
  irrecv.enableIRIn();
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
if (irrecv.decode(&results)) {

  
  if (results.value==0xE0E016E9){ //Code to turn the LED ON/OFF
    if(state==0){ // if the LED was turned off, then we turn it on 
      digitalWrite(9,HIGH);
      digitalWrite(10,HIGH);
      digitalWrite(6,HIGH);
      analogWrite(9,redValue);
      analogWrite(10,blueValue);
      analogWrite(6,greenValue);
      state=1;
    }
    else{
      digitalWrite(9,LOW);
      digitalWrite(10,LOW);
      digitalWrite(6,LOW);
      state=0; 
    }
    delay(250);
  }
    
    
    
    
  if (results.value==0xE0E0A25D && state==1){ //Code to increase the brightness
    if(redValue>249){ 
      analogWrite(9,redValue);
    }
    else{
    redValue=redValue+25;
    analogWrite(9,redValue);
  }
delay(250);
}

  if (results.value==0xE0E0926D && state==1){ //Code to decrease the brightness
    if(redValue<25){ 
      analogWrite(9,redValue);
    }
    else{
    redValue=redValue-25;
    analogWrite(9,redValue);
  }
delay(250);
}
  
  
  
  
  
  
    if (results.value==0xE0E052AD && state==1){ //Code to increase the brightness
    if(blueValue>249){ 
      analogWrite(10,blueValue);
    }
    else{
    blueValue=blueValue+25;
    analogWrite(10,blueValue);
  }
delay(250);
}

  if (results.value==0xE0E0E21D && state==1){ //Code to decrease the brightness
    if(blueValue<25){ 
      analogWrite(10,blueValue);
    }
    else{
    blueValue=blueValue-25;
    analogWrite(10,blueValue);
  }
delay(250);
}



    if (results.value==0xE0E012ED && state==1){ //Code to increase the brightness
    if(greenValue>249){ 
      analogWrite(6,greenValue);
    }
    else{
    greenValue=greenValue+25;
    analogWrite(6,greenValue);
  }
delay(250);
}

  if (results.value==0xE0E0629D && state==1){ //Code to decrease the brightness
    if(greenValue<25){ 
      analogWrite(6,greenValue);
    }
    else{
    greenValue=greenValue-25;
    analogWrite(6,greenValue);
  }
delay(250);
}





  
  irrecv.resume();
}
}
