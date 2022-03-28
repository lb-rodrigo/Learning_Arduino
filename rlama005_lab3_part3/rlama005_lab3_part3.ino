// C++ code
//
enum States{Start, ADD_REL, ADD_PRESS, 
            SUB_REL, SUB_PRESS, RESET_PRESS, RESET_REL}state;

const int LED[] = {2,3,4,5,6,7,8,9};
int button = A0;
int button2 = A1;
byte counter = 7;

void Tick(){
  switch(state){
    case Start:
    
      state = ADD_REL;
      break;
///////////////ADD RELEASED///////////////////
    case ADD_REL:
    if(digitalRead(button) == HIGH){
      if(counter != 10){counter++;}
      state = ADD_PRESS;
    }
    else if(digitalRead(button2) == HIGH){
      if(counter != 0){counter--;}
        state = SUB_PRESS;
    }
    else{
    for(int i = 0; i < 8; i++){
        digitalWrite(LED[i], bitRead(counter, i));
        }
          state = ADD_REL;
      
    }
    break;
/////////////////ADD PRESSED////////////////////////////////
    case ADD_PRESS:
      if((digitalRead(button2) == HIGH)){
            counter = 0;
            state = RESET_PRESS;
        }
      else if(digitalRead(button) == HIGH){
      for(int i = 0; i < 8; i++){
        digitalWrite(LED[i], bitRead(counter, i));
        }
          state = ADD_PRESS;
    }
      else{
          state = ADD_REL;
      }
      break;
///////////////////SUB PRESSED///////////////////////
  case SUB_PRESS:
   
       if((digitalRead(button)== HIGH)){
            counter = 0;
            state = RESET_PRESS;
        }
       else if(digitalRead(button2) == HIGH){
        for(int i = 0; i < 8; i++){
          digitalWrite(LED[i], bitRead(counter, i));
          }
          state = SUB_PRESS;
      }
      else{
          state = SUB_REL;
        }
      break;
///////////////////SUB RELEASED///////////////////////
  case SUB_REL:
      if(digitalRead(button2) == HIGH){
        if(counter != 0){counter--;}
            state = SUB_PRESS;
      }
      else if(digitalRead(button) == HIGH){
          if(counter != 10){counter++;}
            state = ADD_PRESS;
        }
      else{
          for(int i = 0; i < 8; i++){
          digitalWrite(LED[i], bitRead(counter, i));
          }
            state = ADD_REL;
        }
    
      break;
///////////////////RESEAT PRESSED///////////////
    case RESET_PRESS:
      if((digitalRead(button)== HIGH) && 
           (digitalRead(button2) == HIGH)){
              
              counter = 0;
              for(int i = 0; i < 8; i++){
            digitalWrite(LED[i], bitRead(counter, i));
            }
              state = RESET_PRESS;
          
        }
          else{
              state = RESET_REL;
          }
      break;
/////////////////RESET RELEASED////////////
     case RESET_REL:
    if(digitalRead(button) == HIGH){
          if(counter != 10){counter++;}
          state = ADD_PRESS;
      }
      else if(digitalRead(button2) == HIGH){
          if(counter != 0){counter--;}
          state = SUB_PRESS;
      }
      else{
      for(int i = 0; i < 8; i++){
          digitalWrite(LED[i], bitRead(counter, i));
          }
            state = ADD_REL;
      
    }
    break;
  }
}


void setup(){
  
   for(int i=0; i<8; i++){  
    pinMode(LED[i], OUTPUT);
  }
  
}

void loop(){
  
  state = Start;
  while(1){
    Tick();
  }
}
