// C++ code
//
#include <Servo.h>
enum States{Start, ROTATE_SERVO}state;

Servo WindMill;
int potPin = A2;
int mapping;
int volumen;
int cordenates = 0;

void Tick(){
  switch(state){
    case Start:
    
      state =  ROTATE_SERVO;
      break;
      
     case ROTATE_SERVO:
      
      volumen = analogRead(potPin);

      if(cordenates!= volumen){
        volumen = analogRead(potPin);
        cordenates = volumen;
        }
      mapping = map(cordenates, 0, 1023, 0, 180);
      WindMill.write(mapping);

      
      
      state = ROTATE_SERVO;
      
      break;
    
    default:
      break;
  }
}

void setup(){
  
  pinMode(potPin, INPUT);
  WindMill.attach(3);
}

void loop(){
  state = Start;
  
  while(1){
    delay(50);
    Tick();
  }
}
