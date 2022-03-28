// C++ code
//
enum States{Start, LIGHT_1, LIGHT_2, LIGHT_3, LIGHT_4, GAME_OVER}state;

const int LED[] = {0,1,2,3,4};
const int rando[] = {1,2,4,8};

int button = A0;
int button2 = A1;
int button3 = A2;
int button4 = A3;

boolean FirstMove = true;

int index = 0;
int ticks = 0;
byte counter = 1;

void Tick(){
  switch(state){
    case Start:

        index = random(0,4);
        counter = rando[index];
        if(digitalRead(button) == HIGH){
                if(counter == 1){
                  ticks = 1;
                  state = LIGHT_1; 
                }     
             }
             else if(digitalRead(button2) == HIGH){
                if(counter == 2){
                  ticks = 1;
                  state = LIGHT_2; 
                 }     
              }
             else if(digitalRead(button3) == HIGH){
                  if(counter == 4){
                     ticks = 1;
                      state = LIGHT_3;
                   }
              }
             else if(digitalRead(button4) == HIGH){
                  if(counter == 8){
                    ticks = 1;
                    state = LIGHT_4;
                  }   
              }
      if(ticks%10 == 0){
        for(int i = 0; i < 4; i++){
          digitalWrite(LED[i], bitRead(counter, i));    
        }
        state = Start;
      }
       break;
///////////////LIGHT ONE///////////////
    case LIGHT_1:
      if(ticks%5 == 0){
        state = GAME_OVER;
      }
      if(digitalRead(button) == HIGH){   
        ticks = 1;
        counter = 2;
          for(int i = 0; i < 4; i++){
          digitalWrite(LED[i], bitRead(counter, i));
          }
         state = LIGHT_2;
      }
    break;
///////////////LIGHT TWO///////////////
    case LIGHT_2:
      if(ticks%5 == 0){
        state = GAME_OVER;
      }
      if(digitalRead(button2) == HIGH){   
        ticks = 1;
        counter = 4;
          for(int i = 0; i < 4; i++){
          digitalWrite(LED[i], bitRead(counter, i));
          }
         state = LIGHT_3;
      }
    break;
///////////////LIGHT THREE///////////////
    case LIGHT_3:
      if(ticks%5 == 0){
        state = GAME_OVER;
      }
      if(digitalRead(button3) == HIGH){   
        ticks = 1;
        counter = 8;
          for(int i = 0; i < 4; i++){
          digitalWrite(LED[i], bitRead(counter, i));
          }
         state = LIGHT_4;
      }
    break;   
///////////////LIGHT FOUR///////////////
    case LIGHT_4:
      if(ticks%5 == 0){
        state = GAME_OVER;
      }
      if(digitalRead(button4) == HIGH){   
        ticks = 1;
        counter = 1;
          for(int i = 0; i < 4; i++){
          digitalWrite(LED[i], bitRead(counter, i));
          }
         state = LIGHT_1;
      }
    break;
////////////////GAME OVER///////////////////
    case GAME_OVER:
            digitalWrite(LED[0], LOW);
            digitalWrite(LED[1], LOW);
            digitalWrite(LED[2], LOW);
          digitalWrite(LED[3], LOW);
                digitalWrite(LED[4], HIGH);
        state = GAME_OVER;
    break;   
    }
  }

void setup(){
  for(int i=0; i<5; i++){  
      pinMode(LED[i], OUTPUT);
   }
   randomSeed( analogRead(A5) );
}

void loop(){
  state = Start;
  
  
  while(1){
    ticks++;
    delay(100);
    Tick();
    
  }
}