//Test 1: candy dispenser
//01/06/2019
//for makerclub


/*NOTES:

we need:
20x4 i2c lcd screen lib
rotary encoder lib
servo lib

flow:
     Welcome to     
   Candy Dispenser  
   Maker Club 2019  
Press knob to begin.
____________________

<-Hershey's Kisses->
                    
Turn to select candy
Press knob to select
____________________

Place cup under     
Hershey's Kisses    
Ready? Press knob to
dispense...         
____________________

Select another candy
                    
    [NO]    YES     
                    
____________________

  //lcd.print("Hello, world!");
  //lcd.home();
  //lcd.setCursor(0, 1);
  //display() or noDisplay() (on/off)



*/

#include <Encoder.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <Bounce2.h>


#define SERVO_PIN_1 8
#define SERVO_PIN_2 9
#define SERVO_PIN_3 10
#define SERVO_PIN_4 11

#define BUTTON_PIN 12

#define BACKLIGHT_TIMEOUT 5000
#define HOMESCREEN_TIMEOUT 10000


LiquidCrystal_I2C lcd(0x27, 20, 4);

Encoder encoder(2, 3);
Bounce button = Bounce();

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;

int state = 0;
int candy = 1;

void dispense(int servoIndex) {

  switch(servoIndex) {
    case 1:
      Serial.println("Dispensing candy #1");
      //servo1.write(pos);
      break;
    case 2:
      Serial.println("Dispensing candy #2");
      
      break;
    case 3:
      Serial.println("Dispensing candy #3");
      
      break;
    case 4:
      Serial.println("Dispensing candy #4");
      
      break;
    default:
      Serial.println("Error, undef servo");
      break;
  }
  
}

void printCandy(int candy, bool arrows) {
  lcd.backlight();
  if (arrows) {
    switch (candy) {
      case 1:
        lcd.print("<-Hershey's Kisses->");
        break;
      case 2:
        lcd.print("<-    Skittles    ->");
        break;
      case 3:
        lcd.print("<-  Jelly Beans   ->");
        break;
      case 4:
        lcd.print("<-Sour Patch Kids ->");
        break;    
    }
  } else {
    switch (candy) {
      case 1:
        lcd.print("Hershey's Kisses");
        break;
      case 2:
        lcd.print("Skittles");
        break;
      case 3:
        lcd.print("Jelly Beans");
        break;
      case 4:
        lcd.print("Sour Patch Kids");
        break;    
    }
  }
}

void setup() {
  //init lcd
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.noCursor();
  lcd.noBlink();

  //init encoder
  button.attach(BUTTON_PIN, INPUT_PULLUP);
  button.interval(25);
  
  //init servos
  servo1.attach(SERVO_PIN_1);
  servo2.attach(SERVO_PIN_2);
  servo3.attach(SERVO_PIN_3);
  servo4.attach(SERVO_PIN_4);

  //set up serial
  Serial.begin(9600);

  //set up scene
  state=0;
}

void loop() {
  // put your main code here, to run repeatedly:

  long unsigned timer;
  bool again = false;

  switch (state) {
    case 0:

      //print message
      //lcd.backlight();
      lcd.clear();
      lcd.home();
      lcd.print("     Welcome to     ");
      lcd.setCursor(0, 1);
      lcd.print("   Candy Dispenser  ");
      lcd.setCursor(0, 2);
      lcd.print("   Maker Club 2019  ");
      lcd.setCursor(0, 3);
      lcd.print("Press knob to begin.");

      //wait for encoder input and set backlight timer
      timer = millis();
      while(encoder.read() == 0 && !button.fell()) {
        //after backlight timeout is reached
        if (millis() > timer + BACKLIGHT_TIMEOUT) {
          lcd.noBacklight();
        }
      }

      encoder.write(0);

      //go to next screen
      state = 1;
      
      break;


    case 1:
    
      //print message
      lcd.backlight();
      lcd.clear();
      lcd.home();
      printCandy(1, true);
      lcd.setCursor(0, 2);
      lcd.print("Turn to select candy");
      lcd.setCursor(0, 3);
      lcd.print("Press knob to select");

      //start timer
      timer = millis();

      //wait until button is let go and check timers
      while(!button.rose()) {
        //after backlight timeout is reached
        if (millis() > timer + BACKLIGHT_TIMEOUT) {
          lcd.noBacklight();
        }

        //after backlight timeout is reached
        if (millis() > timer + HOMESCREEN_TIMEOUT) {
          state = 0;
          break;
          break;
        }
      }

      candy = 1;

      //wait for interaction and check timers
      while (!button.fell()) {
        //debug
        Serial.print("candy: ");
        Serial.println(candy);

        timer = millis();
        while(encoder.read() == 0 && !button.fell()) {
          //after backlight timeout is reached
          if (millis() > timer + BACKLIGHT_TIMEOUT) {
            lcd.noBacklight();
          }
  
          //after backlight timeout is reached
          if (millis() > timer + HOMESCREEN_TIMEOUT) {
            state = 0;
            break;
            break;
          }
        }

        //encoder turned, record candy change
        if (encoder.read() < 0) {
          //CW
          candy--;
          if (candy == 0) {
            candy = 4;
          }
          encoder.write(0);
        } else if (encoder.read() > 0) {
          //CCW
          candy++;
          if (candy == 5) {
            candy = 0;
          }
          encoder.write(0);
        }

        //print candy change
        lcd.home();
        printCandy(candy, true);
        
      }

      //button pressed, change screen
      state = 2;

      break;
      
    case 2:     
      
      //print message
      lcd.backlight();
      lcd.clear();
      lcd.home();
      lcd.print("Place cup under     ");
      lcd.setCursor(0, 1);
      printCandy(candy, false);
      lcd.setCursor(0, 2);
      lcd.print("Ready? Press knob to");
      lcd.setCursor(0, 3);
      lcd.print("dispense...         ");

      //start timer
      timer = millis();

      //wait until button is let go and check timers
      while(!button.rose()) {
        //after backlight timeout is reached
        if (millis() > timer + BACKLIGHT_TIMEOUT) {
          lcd.noBacklight();
        }

        //after backlight timeout is reached
        if (millis() > timer + HOMESCREEN_TIMEOUT) {
          state = 0;
          break;
          break;
        }
      }

      //start timer
      timer = millis();

      //wait until button is let go and check timers
      while(!button.fell()) {
        //after backlight timeout is reached
        if (millis() > timer + BACKLIGHT_TIMEOUT) {
          lcd.noBacklight();
        }

        //after backlight timeout is reached
        if (millis() > timer + HOMESCREEN_TIMEOUT) {
          state = 0;
          break;
          break;
        }
      }
      
      //dispense candy
      dispense(candy);
      
      //go to next screen
      state = 3

      break;

      
    case 3:

      //start timer
      timer = millis();

      //wait until button is let go and check timers
      while(!button.rose()) {
        //after backlight timeout is reached
        if (millis() > timer + BACKLIGHT_TIMEOUT) {
          lcd.noBacklight();
        }

        //after backlight timeout is reached
        if (millis() > timer + HOMESCREEN_TIMEOUT) {
          state = 0;
          break;
          break;
        }
      }

      //start timer
      timer = millis();

      while(!button.fell()) {
        //print message
        lcd.backlight();
        lcd.clear();
        lcd.home();
        lcd.print("Select another candy");
        lcd.setCursor(0, 2);
        if (again) {
          lcd.print("     NO    [YES]    ");
        } else {
          lcd.print("    [NO]    YES     "); 
        }

        timer = millis();
        while(encoder.read() == 0 && !button.fell()) {
          //after backlight timeout is reached
          if (millis() > timer + BACKLIGHT_TIMEOUT) {
            lcd.noBacklight();
          }
  
          //after backlight timeout is reached
          if (millis() > timer + HOMESCREEN_TIMEOUT) {
            state = 0;
            break;
            break;
          }
        }

        if (encoder.read != 0) {
          again = !again;
          encoder.write(0);
        }
        
      }

      if (again) {
        state = 1;
      } else {
        state = 0;
        //lcd.noBacklight();
      }

      break;

  }

}
