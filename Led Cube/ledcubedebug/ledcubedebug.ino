//Array for three LED levels
int ledRow[] ={ 2,3,4 };
// Array for nine LED's in each level
int ledCol[]= { 5, 6, 7, 8, 9, 10, 11, 12, 13 };
//random col and row
int col0 = 2;
int row0 = 5;
int col1 = 2;
int row1 = 5;
int sped = 350;
int brig = 1023;

void setup() 
{  
  //set all PinModes and make all LEDs low
  for(int i =  0; i < 3; i++) { pinMode( ledRow[i],OUTPUT); digitalWrite(i, LOW); }
  for(int j =  0; j < 9; j++) { pinMode( ledCol[j],OUTPUT); digitalWrite(j, LOW); }
  //seed random functions
}

void loop() {
  digitalWrite(2, HIGH);
  digitalWrite(5, HIGH);
  
  delay(500);
  digitalWrite(2, LOW);
  digitalWrite(5, LOW);
 delay(500);
}
