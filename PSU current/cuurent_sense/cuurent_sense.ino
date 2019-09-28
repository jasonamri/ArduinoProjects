


// Define the number of samples to keep track of.  The higher the number,
// the more the readings will be smoothed, but the slower the output will
// respond to the input.  Using a constant rather than a normal variable lets
// use this value to determine the size of the readings array.
const int numReadings = 100;

int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
float total = 0;                  // the running total
float average = 0;                // the average
float cal1 = 0;
int inputPin = A1;

void setup() {
  // initialize serial communication with computer:
  Serial.begin(9600);
  // initialize all the readings to 0:
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}

void loop() {

  total = total - readings[readIndex];
  readings[readIndex] = analogRead(inputPin) * 100;
  total = total + readings[readIndex];
  readIndex = readIndex + 1;
  if (readIndex >= numReadings) { readIndex = 0; }
  average = ((total / numReadings) / 7.445141)-cal1;


  if (millis() > 10000 && millis() < 10200) {
    cal1 = average;

  }


  

  // send it to the computer as ASCII digits
  if (average > 0) {
    Serial.println(average);
  }
  delay(1);        // delay in between reads for stability
}

void average1 () {
  
}


void average2 () {
  
}

