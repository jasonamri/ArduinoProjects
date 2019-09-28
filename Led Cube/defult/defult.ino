//Code based on ABrushFX Cube code at
//http://www.abrushfx.com/Arduino/ledcube3.html

//Array for three LED levels
int ledRow[] ={ 2,3,4};
// Array for nine LED's in each level
int ledCol[]= { 5, 6, 7, 8, 9, 10, 11, 12, 13 };
int timer= 500;

void setup() // Sets up all pins as Outputs
{  
  for( int i =  0; i < 3; i++)
  
  {
  pinMode( ledRow[i],OUTPUT);
  }

    {  
      for(int j =  0; j < 9; j++)
     
      {
      pinMode( ledCol[j],OUTPUT);
      }
    }
}
// Sets an LED HIGH based on Row and Column position
void onLED(int ledRow, int ledCol){
  
  digitalWrite(ledRow, HIGH); 
  digitalWrite(ledCol, HIGH); 
  
}

// Sets an LED LOW based on Row and Column position
void offLED(int ledRow, int ledCol)
{
  digitalWrite(ledRow, LOW); 
  digitalWrite(ledCol, LOW); 
}

void topRowPaneFigure8()
    {
      for(int y = 0; y < 3; y++)   // light LED's 1 - 3 on/off on top level
        
      {
        onLED(ledRow[0],ledCol[y]);         // 7 8 9
        delay(timer);                       // 4 5 6
        offLED(ledRow[0],ledCol[y]);        // 1 2 3
      }
       for(int y = 5; y > 2; y--)  // light LED's 6 - 4 on/off on top level
      {
        onLED(ledRow[0],ledCol[y]);
        delay(timer);
        offLED(ledRow[0],ledCol[y]);
      }
       for(int y = 6; y < 9; y++)  // light LED's 7 - 9 on/off on top level
      {
        onLED(ledRow[0],ledCol[y]);
        delay(timer);
        offLED(ledRow[0],ledCol[y]);
      }
    
  
  }
  

void centreRowPaneFigure8()
    {
      for(int y = 0; y < 3; y++)    // light LED's 1 - 3 on/off on centre level
        
      {
        onLED(ledRow[1],ledCol[y]);           // 7 8 9
        delay(timer);                         // 4 5 6
        offLED(ledRow[1],ledCol[y]);          // 1 2 3
      }
       for(int y = 5; y > 2; y--)   // light LED's 6 - 4 on/off on centre level
      {
        onLED(ledRow[1],ledCol[y]);
        delay(timer);
        offLED(ledRow[1],ledCol[y]);
      }
       for(int y = 6; y < 9; y++)   // light LED's 7 - 9 on/off on centre level
      {
        onLED(ledRow[1],ledCol[y]);
        delay(timer);
        offLED(ledRow[1],ledCol[y]);
      }
      
  
  }
  
  void bottomRowPaneFigure8()
    {
      for(int y = 0; y < 3; y++)   // light LED's 1 - 3 on/off on bottom level
        
      {
        onLED(ledRow[2],ledCol[y]);          // 7 8 9
        delay(timer);                        // 4 5 6
        offLED(ledRow[2],ledCol[y]);         // 1 2 3
      }
       for(int y = 5; y > 2; y--)   // light LED's 6 - 4 on/off on bottom level
      {
        onLED(ledRow[2],ledCol[y]);
        delay(timer);
        offLED(ledRow[2],ledCol[y]);
      }
       for(int y = 6; y < 9; y++)   // light LED's 7 - 9 on/off on bottom level
      {
        onLED(ledRow[2],ledCol[y]);
        delay(timer);
        offLED(ledRow[2],ledCol[y]);
      }
      
  
  }
  
  
void loop()
{
  topRowPaneFigure8();
  centreRowPaneFigure8();
  bottomRowPaneFigure8();
}

