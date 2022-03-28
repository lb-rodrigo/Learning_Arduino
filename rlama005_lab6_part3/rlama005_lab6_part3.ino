// C++ code
//
#include <Servo.h>
enum States{Start, BUTTON_1, BUTTON_1P, BUTTON_2, BUTTON_2P,
             BUTTON_3, BUTTON_3P, BUTTON_4, BUTTON_4P,
            DEADBOLT} state;

Servo WindMill;

int button = A0;
int button2 = A1;
int button3 = A2;
int button4 = A3;
int degree = 0;

bool one = false;
bool two = false;
bool three = false;
bool four = false;

void Tick(){
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
               &&(four ==  false)){
              state = BUTTON_1P;
            }
      }
      else if(digitalRead(button) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
            state = BUTTON_3;
        }
      else if(digitalRead(button2) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
            state = BUTTON_3;
        }
      else if(digitalRead(button4) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
            state = BUTTON_3;
        }
      break;
 ////////////////////////
    case BUTTON_1P:
      if(digitalRead(button3) == HIGH){
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
               &&(four ==  false)){
              state = BUTTON_4P;
            }
      }
      else if(digitalRead(button3) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
            state = BUTTON_3;
        }
      else if(digitalRead(button2) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
            state = BUTTON_3;
        }
      else if(digitalRead(button4) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
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
               &&(two ==  false)){
              state = BUTTON_2P;
            }
      }
      else if(digitalRead(button3) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
            state = BUTTON_3;
        }
      else if(digitalRead(button) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
            state = BUTTON_3;
        }
      else if(digitalRead(button2) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
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
               &&(four ==  true)){
              state = DEADBOLT;
            }
      }
      else if(digitalRead(button3) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
            state = BUTTON_3;
        }
      else if(digitalRead(button) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
            state = BUTTON_3;
        }
      else if(digitalRead(button4) == HIGH){
          one = false;
            two = false;
            three = false;
            four = false;
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
            state = BUTTON_3;
      break;
    
   }
}


void setup(){
  
  pinMode(button, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  
  WindMill.attach(3);
}

void loop(){
  state = Start;
  
  while(1){
  //delay(50)
   Tick();
  }
}
