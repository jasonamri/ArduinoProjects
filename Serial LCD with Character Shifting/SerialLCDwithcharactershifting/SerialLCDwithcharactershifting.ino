#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(6, 5, 9, 10, 11, 12);
int line = 0;
int preline = 0;
void setup(){
    // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // initialize the serial communications:
  Serial.begin(9600);
}

void loop()
{
  // when characters arrive over the serial port...
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    
    if (Serial.available() > 16) {
      lcd.clear();
      for (int i=0; i <= 15; i++) {
      lcd.write(Serial.read());
      }
      
      lcd.setCursor(0,1);
      
      while (Serial.available() > 0) {
      lcd.write(Serial.read());
      }
      
      line = 0;
      
    } else {
      
        lcd.clear();
         while (Serial.available() > 0) {
           // display each character to the LCD
           lcd.write(Serial.read());
           line = 1;
         }
      
     
    }
  }
}
