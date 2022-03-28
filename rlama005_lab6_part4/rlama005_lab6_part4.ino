#include <Servo.h>

Servo WindMill;

int button = A0;
int button2 = A1;
int button3 = A2;
int button4 = A3;
int button5 = A4;
int potPin = A5;

int voltage;
int degree = 0;

int LED = 4;

bool one = false;
bool two = false;
bool three = false;
bool four = false;
bool five = false;

typedef struct task {
  int state;
  unsigned long period;
  unsigned long elapsedTime;
  int (*TickFct)(int);
} task;

const unsigned short tasksNum = 2;
task tasks[tasksNum];

enum BL_States { Start, BUTTON_1, BUTTON_1P, BUTTON_2, BUTTON_2P,
                 BUTTON_3, BUTTON_3P, BUTTON_4, BUTTON_4P, BUTTON_5, BUTTON_5P, DEADBOLT };

enum TL_States { Start2, ON, OFF };
                 
int TickFct_BlinkLed(int state) {
  switch(state){
    case Start:
      WindMill.write(0);
      state = BUTTON_3;
      break;
////////////////////////////////////    
    case BUTTON_3:
      if(digitalRead(button3) == HIGH){
        three = true;
            if((one == false) && (two == false) 
               &&(four ==  false) && (five == false)){
              state = BUTTON_5P;
            }
      }
      else if(digitalRead(button) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
            five = false;
            state = BUTTON_3;
        }
      else if(digitalRead(button2) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
            five = false;
            state = BUTTON_3;
        }
      else if(digitalRead(button4) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
            five = false;
            state = BUTTON_3;
        }
        else if(digitalRead(button5) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
            five = false;
            state = BUTTON_3;
        }
      break;
 ////////////////////////
  case BUTTON_5P:
      if(digitalRead(button3) == HIGH){
          state = BUTTON_5P;
        }
      else{
        state = BUTTON_5;
        }
      break;
 ////////////////////////
 case BUTTON_5:
      if(digitalRead(button5) == HIGH){
        five = true;
            if((one == false) && (two == false) 
               &&(four ==  false) && (three == true)){
              state = BUTTON_1P;
            }
      }
      else if(digitalRead(button) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
            five = false;
            state = BUTTON_3;
        }
      else if(digitalRead(button2) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
            five = false;
            state = BUTTON_3;
        }
      else if(digitalRead(button4) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
            five = false;
            state = BUTTON_3;
        }
        else if(digitalRead(button5) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
            five = false;
            state = BUTTON_3;
        }
      break;
 ////////////////////////
    case BUTTON_1P:
      if(digitalRead(button5) == HIGH){
          state = BUTTON_1P;
        }
      else{
        state = BUTTON_1;
        }
      break;
////////////////////////////    
    case BUTTON_1:
      if(digitalRead(button) == HIGH){
        one = true;
            if((three == true) && (two == false) 
               &&(four ==  false) && (five == true)){
              state = BUTTON_4P;
            }
      }
      else if(digitalRead(button3) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
            five = false;
            state = BUTTON_3;
        }
      else if(digitalRead(button2) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
            five = false;
            state = BUTTON_3;
        }
      else if(digitalRead(button4) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
            five = false;
            state = BUTTON_3;
        }
        else if(digitalRead(button5) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
            five = false;
            state = BUTTON_3;
        }
      break;
 ////////////////////////
    case BUTTON_4P:
      if(digitalRead(button) == HIGH){
          state = BUTTON_4P;
        }
      else{
        state = BUTTON_4;
        }
      break;
////////////////////////////    
    case BUTTON_4:
      if(digitalRead(button4) == HIGH){
        four = true;
            if((three == true) && (one == true) 
               &&(two ==  false) && (five == true)){
              state = BUTTON_2P;
            }
      }
      else if(digitalRead(button3) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
            five = false;
            state = BUTTON_3;
        }
      else if(digitalRead(button) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
            five = false;
            state = BUTTON_3;
        }
      else if(digitalRead(button2) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
            five = false;
            state = BUTTON_3;
        }
        else if(digitalRead(button5) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
            five = false;
            state = BUTTON_3;
        }
      break;
 ////////////////////////
    case BUTTON_2P:
      if(digitalRead(button4) == HIGH){
          state = BUTTON_2P;
        }
      else{
        state = BUTTON_2;
        }
      break;
////////////////////////////    
    case BUTTON_2:
      if(digitalRead(button2) == HIGH){
        two = true;
            if((three == true) && (one == true) 
               &&(four ==  true) && (five == true)){
              state = DEADBOLT;
            }
      }
      else if(digitalRead(button3) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
            five = false;
            state = BUTTON_3;
        }
      else if(digitalRead(button) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
            five = false;
            state = BUTTON_3;
        }
      else if(digitalRead(button4) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
            five = false;
            state = BUTTON_3;
        }
        else if(digitalRead(button5) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
            five = false;
            state = BUTTON_3;
        }
      break;
 ////////////////////////
    case DEADBOLT:
      if(degree == 0){
          degree = 180; 
            WindMill.write(degree);
        }
      else if (degree == 180){
        degree = 0;
            WindMill.write(degree);
      }
        one = false;
            two = false;
            three = false;
            four = false;
            five = false;
            state = BUTTON_3;
      break;
    
   }
  
  return state; }


  int TickFct_ThreeLeds(int state) { 
  
    switch(state){
    case Start:
      state = OFF;
      break; 
    case ON:
      if (voltage > 40){
      
            digitalWrite(LED, LOW);
          state = OFF;
      }
      else{
          digitalWrite(LED, HIGH);
          state = ON;
        }
      break;
    
    case OFF:
    if(voltage > 40){
        
        state = OFF;
    }
    else{
      state = ON;
    } 
    break;
    }
    
    return state; }

  
void setup() {

  pinMode(potPin, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
  WindMill.attach(3);
  
  unsigned char i = 0;
  tasks[i].state = Start;
  tasks[i].period = 100;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &TickFct_BlinkLed;
   i++;
  tasks[i].state = Start2;
  tasks[i].period = 100;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &TickFct_ThreeLeds;
}

void loop() {
  // put your main code here, to run repeatedly:
  voltage = analogRead(A5);
  Serial.println(voltage);
  
  unsigned char i;
  for (i = 0; i < tasksNum; ++i) {
    if ( (millis() - tasks[i].elapsedTime) >= tasks[i].period) {
        tasks[i].state = tasks[i].TickFct(tasks[i].state);
        tasks[i].elapsedTime = millis(); // Last time this task was ran
    }
  }
  delay(100);
}
