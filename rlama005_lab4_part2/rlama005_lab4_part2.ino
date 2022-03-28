// C++ code
//
enum States{Start, GAME_ON, GAME_OVER, RESET}state;

const int LED[] = {2,3,4};
int button = A0;
int ticks = 0;
byte counter = 1;

void Tick(){
  switch(state){
    case Start:
    
      state = GAME_ON;
      break;
////////////GAME ON/////////////////
    case GAME_ON:
  ////////////////LIGHT SHOW HERE/////////      
    if(ticks%3 == 0){
      for(int i = 0; i < 3; i++){
          if(counter == 3){
            counter = 4;
          }
          else if(counter == 5){
          counter = 1;
           i = 0;
          }
        digitalWrite(LED[i], bitRead(counter, i));
            
        }
    
      counter++;
      } 
      
      if(digitalRead(button) == HIGH){
              state = GAME_OVER;
      }
     

    
    break;
////////////////GAME OVER///////////////////
    case GAME_OVER:
    if(digitalRead(button) == HIGH){
      state = GAME_OVER;
    }
    else{
        counter = 1;
      state = RESET;
    }
    break;
////////////////RESET///////////////////
    case RESET:
    if(digitalRead(button) == HIGH){
 
        state = GAME_ON;
    }
    else{
      state = RESET;
    }
  }
}


void setup(){
  
   for(int i=0; i<3; i++){  
      pinMode(LED[i], OUTPUT);
   }
}

void loop(){
  
  state = Start;
  
  
  while(1){
    ticks++;
    delay(100);
    Tick();
    
  }
}
