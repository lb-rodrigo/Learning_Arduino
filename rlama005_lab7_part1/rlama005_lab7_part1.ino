#include <LiquidCrystal.h>


typedef struct task {
  int state;
  unsigned long period;
  unsigned long elapsedTime;
  int (*TickFct)(int);
} task;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int button = A0;
int button2 = A1;
int button3 = A2;
int button4 = A3;
int button5 = A4;
int count = 0;

const unsigned short tasksNum = 1;
task tasks[tasksNum];

enum BL_States { Start, BUTTON, BUTTON_P, BUTTON_5P};

int TickFct_BlinkLed(int state) { 
  
    switch(state){
      case Start:
          lcd.setCursor(0,0);
          state = BUTTON;
          break;
////////////////////////////////////        
        case BUTTON:
        
      if(digitalRead(button) ==  HIGH){
            lcd.write('a');
            count++;
          state = BUTTON_P;
      }
      else if(digitalRead(button2) == HIGH){
            lcd.write('b');
            count++;
          state = BUTTON_P;
            
      }
      else if(digitalRead(button3) == HIGH){
          lcd.write('c');
            count++;
          state = BUTTON_P;
      }
      else if(digitalRead(button4) == HIGH){
          lcd.write('d');
            count++;
          state = BUTTON_P;
      }
      else if(digitalRead(button5) == HIGH){
          state = BUTTON_5P;
      }
      
      if(count == 16){
        lcd.setCursor(0,1);
        state = BUTTON;
      }
          break;
////////////////////
      case BUTTON_P:
        if(digitalRead(button) == HIGH){
          if(digitalRead(button2) == HIGH){lcd.clear();}
          if(digitalRead(button3) == HIGH){lcd.clear();}
          if(digitalRead(button4) == HIGH){lcd.clear();}
      
        state = BUTTON_P;
        }
        else if(digitalRead(button2) == HIGH){
          if(digitalRead(button) == HIGH){lcd.clear();}
          if(digitalRead(button3) == HIGH){lcd.clear();}
          if(digitalRead(button4) == HIGH){lcd.clear();}
         
        state = BUTTON_P;
        }
        else if(digitalRead(button3) == HIGH){
          if(digitalRead(button2) == HIGH){lcd.clear();}
          if(digitalRead(button) == HIGH){lcd.clear();}
          if(digitalRead(button4) == HIGH){lcd.clear();}
          
        state = BUTTON_P;
        }
        else if(digitalRead(button4) == HIGH){
          if(digitalRead(button2) == HIGH){lcd.clear();}
          if(digitalRead(button3) == HIGH){lcd.clear();}
          if(digitalRead(button) == HIGH){lcd.clear();}
         
        state = BUTTON_P;
        }
      else{
        state = BUTTON; 
      }
      break;
/////////////////////////////////
      case BUTTON_5P:
        if(digitalRead(button5) ==  HIGH){
          if(digitalRead(button) == HIGH){
            lcd.write('A');
            count++;
            state = BUTTON_P;
          }
          else if(digitalRead(button2) == HIGH){
            lcd.write('B');
            count++;
            state = BUTTON_P;
          }
          else if(digitalRead(button3) == HIGH){
            lcd.write('C');
            count++;
            state = BUTTON_P;
          }
          else if(digitalRead(button4) == HIGH){
            lcd.write('D');
            count++;
            state = BUTTON_P;
          }
        }
      else{
          state = BUTTON;
      }
        break;
    
    }
  
  return state; }

void setup() {
  lcd.begin(16, 2);
  pinMode(button, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  
  unsigned char i = 0;
  tasks[i].state = Start;
  tasks[i].period = 100;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &TickFct_BlinkLed;
  
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned char i;
  for (i = 0; i < tasksNum; ++i) {
    if ( (millis() - tasks[i].elapsedTime) >= tasks[i].period) {
        tasks[i].state = tasks[i].TickFct(tasks[i].state);
        tasks[i].elapsedTime = millis(); // Last time this task was ran
    }
  }
  delay(100);
}
