#include <SoftPWM.h>

const int button1 = 2;
const int button2 = 3;
const int button3 = 4;

int pins[]={0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int menu=0;

boolean wink=false;

int face=5;

int animation=0;

int animationSpeed=150;

int brightness=255;

int pin1=0;
int pin2=0;
int pin3=0;
int pin4=0;
int pin5=0;
int pin6=0;
int pin7=0;
int pin8=0;
int pin9=0;
int pin10=0;
int pin11=0;
int pin12=0;
int pin13=0;
int pin14=0;



unsigned long previousMillis = 0;

unsigned long currentMillis = 0;

int oldBrightness=255;

void setup() {
  
 
  previousMillis = millis();
  
  SoftPWMBegin(SOFTPWM_NORMAL);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  
  render(brightness);
}

void loop() {
  // put your main code here, to run repeatedly:

if (digitalRead(button1)==LOW) {
  buttonManager(1);
  

}

if (digitalRead(button2)==LOW) {
  buttonManager(2);
  

}

if (digitalRead(button3)==LOW) {
  buttonManager(3);
  

}


delay(1);
animationCheck();

}



void buttonManager(int button) {


  //menu base
  if (menu==0) {
    
    if (button==1) {
      //go to face menu
      menu=1;
      delay(250);
      return;
    }

    if (button==2) {
      //go to animation menu
      menu=4;
      delay(250);
      return;
    }

    if (button==3) {
      //go to brightness menu
      menu=7;
      delay(250);
      return;
    }
    
    
  }


  
  //face menu
  if (menu==1) {
    
    if (button==1) {
      wink= !wink;
      render(brightness);
      menu=0;
      delay(250);
      return;
    }

    if (button==2) {
      menu=2;
      delay(250);
      return;
    }

    if (button==3) {
      menu=3;
      delay(250);
      return;
    }
    
    
  }

  
  //curved menu
  if (menu==2) {
    
    if (button==1) {
      face=0;
      render(brightness);
      menu=0;
      delay(250);
      return;
    }

    if (button==2) {
      face=1;
      render(brightness);
      menu=0;
      delay(250);
      return;
    }

    if (button==3) {
      face=2;
      render(brightness);
      menu=0;
      delay(250);
      return;
    }
    
    
  }


  //straight menu
  if (menu==3) {
    
    if (button==1) {
      face=3;
      render(brightness);
      menu=0;
      delay(250);
      return;
    }

    if (button==2) {
      face=4;
      render(brightness);
      menu=0;
      delay(250);
      return;
    }

    if (button==3) {
      face=5;
      render(brightness);
      menu=0;
      delay(250);
      return;
    }
    
    
  }

  
  //animation menu
  if (menu==4) {
    
    if (button==1) {
      animation=0;
      menu=0;
      delay(250);
      return;
    }

    if (button==2) {
      menu=5;
      animation=1;
      delay(250);
      return;
    }

    if (button==3) {
      menu=6;
      animation=2;
      delay(250);
      return;
    }
    
    
  }


  //jump cut
  if (menu==5) {
    
    if (button==1) {
      if (animationSpeed<240) {
        animationSpeed=animationSpeed+15;
      }
      delay(25);
      return;
    }

    if (button==2) {
      menu=0;
      delay(250);
      return;
    }

    if (button==3) {
      if (animationSpeed>15) {
        animationSpeed=animationSpeed-15;
      }
      delay(25);
      return;
    }
    
    
  }

  
  //fade menu
  if (menu==6) {
     
    if (button==1) {
      if (animationSpeed<240) {
        animationSpeed=animationSpeed+15;
      }
      
      delay(25);
      return;
    }

    if (button==2) {
      menu=0;
      delay(250);
      return;
    }

    if (button==3) {
      if (animationSpeed>15) {
        animationSpeed=animationSpeed-15;
      }
      
      delay(25);
      return;
    }
    
    
  }


  //brightness menu
  if (menu==7) {
    
    if (button==1) {
      if (brightness<240) {
        brightness=brightness+15;
      }
      render(brightness);
      delay(250);
      return;
    }

    if (button==2) {
      menu=0;
      render(brightness);
      delay(250);
      return;
    }

    if (button==3) {
      if (brightness>15) {
        brightness=brightness-15;
      }
      render(brightness);
      delay(250);
      return;
    }
    
    
  }


}



//convert face into pins
void render(int incoming) {

if (incoming==brightness) { 
} else {
  brightness=incoming;
}

  //faces
  if (face==0) {
 pin1=0;
 pin2=1;
 pin3=0;
 pin4=0;
 pin5=0;
 pin6=0;
 pin7=0;
 pin8=1;
 pin9=1;
 pin10=1;
 pin11=0;
 pin12=1;
 pin13=0;
 pin14=0;
  }


  if (face==1) {
 pin1=0;
 pin2=1;
 pin3=0;
 pin4=0;
 pin5=1;
 pin6=0;
 pin7=0;
 pin8=1;
 pin9=1;
 pin10=1;
 pin11=1;
 pin12=1;
 pin13=1;
 pin14=1;
  }

  
  if (face==2) {
 pin1=0;
 pin2=0;
 pin3=0;
 pin4=0;
 pin5=1;
 pin6=0;
 pin7=0;
 pin8=0;
 pin9=0;
 pin10=0;
 pin11=1;
 pin12=0;
 pin13=1;
 pin14=1;
  }

  
  if (face==3) {
 pin1=0;
 pin2=0;
 pin3=1;
 pin4=0;
 pin5=0;
 pin6=0;
 pin7=0;
 pin8=1;
 pin9=1;
 pin10=0;
 pin11=0;
 pin12=0;
 pin13=0;
 pin14=0;
  }

  
  if (face==4) {
 pin1=0;
 pin2=0;
 pin3=1;
 pin4=0;
 pin5=0;
 pin6=1;
 pin7=1;
 pin8=1;
 pin9=1;
 pin10=1;
 pin11=1;
 pin12=1;
 pin13=1;
 pin14=0;
  }

  
  if (face==5) {
 pin1=0;
 pin2=0;
 pin3=1;
 pin4=1;
 pin5=0;
 pin6=1;
 pin7=0;
 pin8=1;
 pin9=1;
 pin10=0;
 pin11=0;
 pin12=1;
 pin13=1;
 pin14=0;
  }


  //wink
  if (wink==true) {
    pin1=1;
  } else {
    pin1=0;
  }


  
if (pin1==1) {
  SoftPWMSet(A4,brightness);
} else {
  SoftPWMSet(A4,0);
}

if (pin2==1) {
  SoftPWMSet(A1,brightness);
} else {
  SoftPWMSet(A1,0);
}

if (pin3==1) {
  SoftPWMSet(A3,brightness);
} else {
  SoftPWMSet(A3,0);
}

if (pin4==1) {
  SoftPWMSet(9,brightness);
} else {
  SoftPWMSet(9,0);
}

if (pin5==1) {
  SoftPWMSet(A0,brightness);
} else {
  SoftPWMSet(A0,0);
}

if (pin6==1) {
  SoftPWMSet(10,brightness);
} else {
  SoftPWMSet(10,0);
}

if (pin7==1) {
  SoftPWMSet(A2,brightness);
} else {
  SoftPWMSet(A2,0);
}

if (pin8==1) {
  SoftPWMSet(8,255-brightness);
} else {
  SoftPWMSet(8,255);
}

if (pin9==1) {
  SoftPWMSet(7,255-brightness);
} else {
  SoftPWMSet(7,255);
}

if (pin10==1) {
  SoftPWMSet(5,255-brightness);
} else {
  SoftPWMSet(5,255);
}

if (pin11==1) {
  SoftPWMSet(6,255-brightness);
} else {
  SoftPWMSet(6,255);
}

if (pin12==1) {
  SoftPWMSet(13,255-brightness);
} else {
  SoftPWMSet(13,255);
}

if (pin13==1) {
  SoftPWMSet(12,255-brightness);
} else {
  SoftPWMSet(12,255);
}

if (pin14==1) {
  SoftPWMSet(11,255-brightness);
} else {
  SoftPWMSet(11,255);
}
  
  
}


void animationCheck() {
  if (animation==0) {
    
  }
  
  if (animation==1) {
    
  }
  
  if (animation==2) {

    currentMillis = millis();

    if(currentMillis - previousMillis >= animationSpeed*10) {
      previousMillis = currentMillis;   
      if (face!=5) {
      face++;
      } else {
        face=0;
      }
      render(brightness);
    }
    
  }
  
}







