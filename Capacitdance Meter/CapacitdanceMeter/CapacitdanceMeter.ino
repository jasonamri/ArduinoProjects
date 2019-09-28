 #include <LiquidCrystal.h>
 LiquidCrystal lcd(8, 6, 5, 4, 3, 2);
 
 float R1 = 1000;                   // variable to store the R1 value
 float R2 = 10000;                  // variable to store the R2 value
 float R3 = 100000;                 // variable to store the R3 value
 float R4 = 1000000;                // variable to store the R4 value
 float R5 = 10000000;
 
 int buttonPin = 1;
 int analogPin = 0;               // analog pin for measuring capacitor voltage
 int dischargePin = 7;
 int chargePin = 9;

 
 int complete = 0;
            
 float startTime;         
 float elapsedTime;  
 
 float microFarads;               // floating point variable to preserve precision, make calculations
 float nanoFarads;                
 
void setup() {
  lcd.begin(16, 2);

  pinMode(dischargePin, INPUT);
  pinMode(chargePin, INPUT);
  pinMode(buttonPin, INPUT);
}


void loop() {
  
  if (analogRead(buttonPin)>1000) {
  
  if (complete==0) {
   lcd.clear(); 
  }
    
  //charge: 
  startTime = millis();
  pinMode(chargePin, OUTPUT);
  digitalWrite(chargePin, HIGH);                    // set chargePin HIGH and capacitor charging
  while(analogRead(analogPin) < 647)  {}           // 647 is 63.2% of 1023, which corresponds to full-scale voltage 
  elapsedTime= millis() - startTime;
  pinMode(chargePin, INPUT);                   // set charge pin to  LOW 
  
  //math:
  if (chargePin==9) {
  microFarads = (elapsedTime / R1) * 1000;
  }
  if (chargePin==10) {
  microFarads = (elapsedTime / R2) * 1000;
  }
  if (chargePin==11) {
  microFarads = (elapsedTime / R3) * 1000;
  }
  if (chargePin==12) {
  microFarads = (elapsedTime / R4) * 1000;
  }
  if (chargePin==13) {
  microFarads = (elapsedTime / R5) * 1000;
  }
  

  
  //discharge:
  pinMode(dischargePin, OUTPUT);                  // set discharge pin to output 
  digitalWrite(dischargePin, LOW);                // set discharge pin LOW 
  while(analogRead(analogPin) > 0){}              // wait until capacitor is completely discharged
  pinMode(dischargePin, INPUT);
  
  //adjust
  if(elapsedTime<100 && chargePin!=13&&complete>0) {
    chargePin++;
  }
  
  
  
  
  //display
  
  nanoFarads = microFarads * 1000.0; 
  lcd.setCursor(0, 0);
  if (microFarads>=1) {
    lcd.print((int)microFarads);
    lcd.print(" microFarads ");
  } else {
    lcd.print(microFarads);
    lcd.print(" microFarads ");
    lcd.setCursor(0, 1);  // multiply by 1000 to convert to nanoFarads (10^-9 Farads)
    lcd.print((long)nanoFarads);                   // print the value to serial port
    lcd.print(" nanoFarads ");
  }

  
  
  complete++;
  
  } else {

    if (complete>0) {
    chargePin=9; 
    complete=0;
  }
    delay(500);
    
  }

}
  
  
  
  /* raw = analogRead(1);            // Reads the Input PIN
  Vout = (5.0 / 1023.0) * raw;    // Calculates the Voltage on th Input PIN
  buffer = (Vin / Vout) - 1;
  R2 = R1 / buffer * 1000; 
  delay(5);
  raw = analogRead(1);            // Reads the Input PIN
  Vout = (5.0 / 1023.0) * raw;    // Calculates the Voltage on th Input PIN
  buffer = (Vin / Vout) - 1;
  R2 = R1 / buffer * 1000;
  if (R2 < 1.25 && R2 > 0.75) {
  R3 = round(R2);
  R4 = R3;
  } else if (R2 < 12.5 && R2 > 7.5) {
  R3 = R2 / 10;
  R3 = round(R3);
  R4 = R3 * 10;
  } else if (R2 < 125 && R2 > 75) {
  R3 = R2 / 100;
  R3 = round(R3);
  R4 = R3 * 100;
  } else if (R2 < 1250 && R2 > 750) {
  R3 = R2 / 1000;
  R3 = round(R3);
  R4 = R3 * 1000;
  } else if (R2 < 12500 && R2 > 7500) {
  R3 = R2 / 10000;
  R3 = round(R3);
  R4 = R3 * 10000;
  } else if (R2 < 125000 && R2 > 75000) {
  R3 = R2 / 100000;
  R3 = round(R3);
  R4 = R3 * 100000;
  } else if (R2 < 1250000 && R2 > 750000) {
  R3 = R2 / 1000000;
  R3 = round(R3);
  R4 = R3 * 1000000;
  } else if (R2 < 12500000 && R2 > 7500000) {
  R3 = R2 / 10000000;
  R3 = round(R3);
  R4 = R3 * 10000000; } */
