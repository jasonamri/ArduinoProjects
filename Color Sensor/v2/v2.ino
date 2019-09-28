//Here is some sample Arduino code that you can use.

//You will need to adjust some of the values to calibrate it to your setup.

Servo myservo; // create servo object to control a servo

int GreenLedPin = 8; // Green LED connected to digital pin 8 
int RedLedPin = 9; // Red LED connected to digital pin 9 
int BlueLedPin = 10; // Blue LED connected to digital pin 10
int analogPin = 0; // photoresistor connected to analog pin 0 

int GreenVal = 0; // variable to store the value of reflected Green light 
int RedVal = 0; // variable to store the value of reflected Red light 
int BlueVal = 0; // variable to store the value of reflected Blue light

int GreenRedDifference = 0; 
int GreenBlueDifference = 0;

int GreenRedLockCode = -31; // lock value 
int GreenBlueLockCode = 47; // lock value

int sensitivity = 5; // set sensitivity of the color sensor



void setup() { 
  myservo.attach(6); // attaches the servo on pin 6 to the servo object
  Serial.begin(9600); // setup serial 
  pinMode(GreenLedPin, OUTPUT); // sets the digital pin as output 
  pinMode(RedLedPin, OUTPUT); // sets the digital pin as output 
  pinMode(BlueLedPin, OUTPUT); // sets the digital pin as output
} 


void loop() {  
  digitalWrite(GreenLedPin, HIGH); // sets the Green LED off 
  digitalWrite(RedLedPin, HIGH); // sets the Red LED off 
  digitalWrite(BlueLedPin, HIGH); // sets the Blue LED off 
  
  delay(50); // waits for a second 
  digitalWrite(GreenLedPin, LOW); // sets the Green LED on 
  delay(50); 
  GreenVal = 1023 - analogRead(analogPin); // read the input pin  
  Serial.print("Green "); 
  Serial.println(GreenVal); // debug value 
  digitalWrite(GreenLedPin, HIGH); // sets the Green LED off 
  
  delay(50); // waits for a second
  digitalWrite(RedLedPin, LOW); // sets the Red LED on 
  delay(50); 
  RedVal = 1023 - analogRead(analogPin); // read the input pin 
  Serial.print("Red "); 
  Serial.println(RedVal); // debug value 
  digitalWrite(RedLedPin, HIGH); // sets the Red LED off 
  
  delay(50); // waits for a second
  digitalWrite(BlueLedPin, LOW); // sets the Blue LED on 
  delay(50); 
  BlueVal = 1023 - analogRead(analogPin); // read the input pin 
  Serial.print("Blue "); 
  Serial.println(BlueVal); // debug value 
  digitalWrite(BlueLedPin, HIGH); // sets the Blue LED off

GreenRedDifference = GreenVal - RedVal; 
Serial.print("Green-Red Difference "); 
Serial.println(GreenRedDifference); // debug value 

GreenBlueDifference = GreenVal - BlueVal; 
Serial.print("Green-Blue Difference "); 
Serial.println(GreenBlueDifference); // debug value

if((abs(GreenRedLockCode-GreenRedDifference) < sensitivity) && (abs(GreenBlueLockCode-GreenBlueDifference) < sensitivity)) { //compare measured color value to code value 
 Serial.println("Unlock"); // unlock the box 
myservo.write(45);
} else { 
  Serial.println("Lock"); // lock the box 
myservo.write(135); 
}

delay(50); 
}



