// C++ code
//
enum States{Start, LOCKED, UNLOCKED}state;

bool upLast = false;
const int LED = 2;
int buttonX = A0;
int buttonY = A1;
int button_GATO  = A2;
int button4 = A4;

void Tick(){
  switch(state){
    case Start:
    
      state = LOCKED;
      break;
///////////////LOCKED///////////////////
    case LOCKED:
    if(digitalRead(button_GATO) == HIGH){
      upLast = true;
      state = LOCKED;
    }
    else if(digitalRead(buttonX) == HIGH){
      upLast = false;
      state = LOCKED;
    }
    else if(digitalRead(button4) == HIGH){
      upLast = false;
      state = LOCKED;
    }
    else if(digitalRead(buttonY) == HIGH){
      if(upLast == true){
        digitalWrite(LED, HIGH);
        state = UNLOCKED;
      }
    }
    else if(digitalRead(buttonY) == HIGH){
      if(upLast == false){
          state = LOCKED;
        }       
    }
    break;
////////////////UNLOCKED//////////////
    case UNLOCKED:
    if(digitalRead(button_GATO) == HIGH){
      upLast = false;
      state = UNLOCKED;
    }
    else if(digitalRead(buttonX) == HIGH){
      upLast = false;
      state = UNLOCKED;
    }
    else if(digitalRead(button4) == HIGH){
      upLast = false;
      digitalWrite(LED, LOW);
      state = LOCKED;
    }
    else if(digitalRead(buttonY) == HIGH){
      upLast = false;
        state = UNLOCKED;
      
    }
    break;
  }
}


void setup(){
  
    pinMode(LED, OUTPUT);

  
}

void loop(){
  
  state = Start;
  while(1){
    Tick();
  }
  
}
