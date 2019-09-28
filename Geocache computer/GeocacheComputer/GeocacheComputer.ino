
//library declaration
#include <LiquidCrystal.h>


//variable declaration
//scene variable
int scene=0;
int oldscene=-1;
//number variable for scene 5,7,18
String s5 = " ";
String olds5 = " ";
//strings to diplay with spaces for display char overflow
char* text[28] = {"Hello! Press any                        button to start.","Next, test the                          number buttons.","If they work as                         planned, Press A","Otherwise,                              Press B.","You should see                          the numbers here","You should see                          them here:","Resetting button                        controller",
"Try now:","Still doesnt                            work, Contact CO","Great! It works!                        Now lets start.","Remember, Press                         A to advance,","Press B to go                           back.","Ok, now move                            onto Stage 2.","Press A when you                        get there:",
"Head 184m South                         East or go to:","  43* 12.13332'                         -079* 59.29206'","Do you see the                          Stone structure?","Go to East side                         & find the sign,","# of letters in                         the 6th word?","The Family home                         was built when?","How many letter                         'E's are there?",
"Good job, now go                        to a street lamp","Are you there?                          Look up","What number do                          you see?","Great Job! Final                        stage is at: ","  43* 12.13770'                         -079* 59.38296'","It's a physical                         stage. Good luck","Please re-hide                          me as found :)"};

LiquidCrystal lcd(12, 11, 10, 9, 5, 6);


void setup() {

  //intialize the lcd
  lcd.begin(16, 2);
  lcd.noCursor();
  lcd.noBlink();
  
  //serial setup
  Serial.begin(9600);

  //pinMode declaration
  pinMode(2,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(3,OUTPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(13,OUTPUT);

  //reset button driver
  digitalWrite(13,LOW);
  digitalWrite(13,HIGH);
  digitalWrite(13,LOW);
  
}



void loop() {
  //vvvv button input

  if (scene==6) {
    delay(1000);
    digitalWrite(13,LOW);
    digitalWrite(13,HIGH);
    digitalWrite(13,LOW); 
    scene=7;
  }

 if (scene==9) {
    delay(1000);
    scene++;
  }
  
  //a button
  if (digitalRead(2)==LOW) {
  Serial.println("hihi");
    //go forward a scene
    if (scene==0||scene==1||scene==2||scene==3||scene==9||scene==10||scene==11||scene==12||scene==13||scene==14||scene==15||scene==16||scene==17||scene==21||scene==22||scene==24||scene==25||scene==26||scene==27) {
      scene++;
      s5=" ";
    }
    
    if (scene==5||scene==7) {
      scene=9;
    }
    
    if (scene==18&&s5=="6") {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Correct!");
      delay(500);
      scene=19;
    } 
    
    if (scene==18&&s5!="6"&&s5!=" ") {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Incorrect!");
      delay(500);
      oldscene=-1;
    }

    if (scene==19&&s5==" 1860") {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Correct!");
      delay(500);
      scene=20;
    } 
    
    if (scene==19&&s5!=" 1860"&&s5!=" ") {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Incorrect!");
      s5=" ";
      olds5=" ";
      delay(500);
      oldscene=-1;
    }

    if (scene==20&&s5==" 16") {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Correct!");
      delay(500);
      scene=21;
    } 
    
    if (scene==20&&s5!=" 16"&&s5!=" ") {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Incorrect!");
      s5=" ";
      olds5=" ";
      delay(500);
      oldscene=-1;
    }

    if (scene==23&&s5==" 25") {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Correct!");
      delay(500);
      scene=24;
    } 
    
    if (scene==23&&s5!=" 25"&&s5!=" ") {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Incorrect!");
      s5=" ";
      olds5=" ";
      delay(500);
      oldscene=-1;
    }
    
  }




  //b button
  if (digitalRead(4)==LOW) {
    //go back a scene
    if (scene==12||scene==13||scene==14||scene==15||scene==16||scene==17||scene==18||scene==22||scene==25||scene==26) {
      scene--;
      
    }
    //go forward a scene (any button)
    if (scene==0||scene==1||scene==2||scene==3||scene==5||scene==7||scene==9||scene==10) {
      scene++;
      
    }

    if (scene==19||scene==20||scene==23&&s5!=" ") {
      int lastIndex = s5.length() - 1;
      s5.remove(lastIndex);
      olds5="-";
    }
    
  }







  for (int i=0; i<=9; i++) {
    digitalWrite(3,HIGH);
    digitalWrite(3,LOW);


    
    if (digitalRead(7)==HIGH) {

      
      //go forward a scene (any button)
      if (scene==0||scene==1||scene==2||scene==3||scene==4||scene==9||scene==10) {
        scene++;
        
      }
      
      
      if (scene==4||scene==5||scene==7||scene==18) {
        switch (i) {
        case 0:
          s5="3";
          break;
        case 1:
          s5="4";
          break;
        case 2:
          s5="7";
          break;
        case 3:
          s5="9";
          break;
        case 4:
          s5="1";
          break;
        case 5:
          s5="6";
          break;
        case 6:
          s5="5";
          break;
        case 7:
          s5="8";
          break;
        case 8:
          s5="hi";
          break;
        case 9:
          s5="2";
          break;
        default: 
          s5="ERROR";
          break;
      }}

      
      if (scene==19||scene==20||scene==23) {
        switch (i) {
        case 0:
          s5+="3";
          break;
        case 1:
          s5+="4";
          break;
        case 2:
          s5+="7";
          break;
        case 3:
          s5+="9";
          break;
        case 4:
          s5+="1";
          break;
        case 5:
          s5+="6";
          break;
        case 6:
          s5+="5";
          break;
        case 7:
          s5+="8";
          break;
        case 8:
          s5+="2";
          break;
        default: 
          error1();
          break;
      }}




    
    }//end if digital read


    
    if (digitalRead(8)==HIGH) {



      //go forward a scene (any button)
      if (scene==0||scene==1||scene==2||scene==3||scene==4||scene==9||scene==10) {
        scene++;
        
      }

     
      if (scene==4||scene==5||scene==7||scene==18) {
        switch (i) {
        case 2:
          s5="*";
          break;
        case 7:
          s5="0";
          break;
        case 3:
          s5="#";
          break;
        default: 
          error1();
          break;
      }}

      if (scene==19||scene==20||scene==23) {
        switch (i) {
        case 2:
          s5+="*";
          break;
        case 7:
          s5+="0";
          break;
        case 3:
          s5+="#";
          break;
        default: 
          error1();
          break;
      }}
    
    }//end if digital read


     
  
    if (scene!=oldscene) {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(text[scene]);
      oldscene=scene;
      delay(500);
    }


    if (scene==5||scene==7||scene==18||scene==19||scene==20||scene==23) {
      if (s5!=olds5) {
        if (scene==5) {
          lcd.setCursor(12,1);
        }
        if (scene==7) {
          lcd.setCursor(9,0);
        }
        if (scene==18) {
          lcd.setCursor(14,1);
        }
        if (scene==19) {
          lcd.setCursor(9,1);
          lcd.print("        ");
          lcd.setCursor(9,1);
        }
        if (scene==20) {
          lcd.setCursor(8,1);
          lcd.print("        ");
          lcd.setCursor(8,1);
        }
        if (scene==23) {
          lcd.setCursor(8,1);
          lcd.print("        ");
          lcd.setCursor(8,1);
        }
        lcd.print(s5);
        //debounce delay
        if (scene==19||scene==20||scene==23) {
          delay(500);
        }
        olds5=s5;
      }
    }
    
      
   
   
    
    
    

    //debounce
    delay(10);
  }
  //^^^^ end button input


}




//errors
//incase of button input error
void error1 () {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ERROR CODE 1");
}







