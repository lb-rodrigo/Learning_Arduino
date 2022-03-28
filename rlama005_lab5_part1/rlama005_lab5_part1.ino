// C++ code
//
enum States{Start, ON, OFF}state;
int potPin = A5;
int voltage; 

int led = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int led7 = 8;
int led8 = 9;


void Tick(){
  
  switch(state){
    case Start:
      state = OFF;
      break; 
    case ON:
      if (voltage < 31){
      
            digitalWrite(led, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            digitalWrite(led4, LOW);
            digitalWrite(led5, LOW);
            digitalWrite(led6, LOW);
            digitalWrite(led7, LOW);
            digitalWrite(led8, LOW);
          state = OFF;
      }
      else if(voltage < 127){
          digitalWrite(led, HIGH);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            digitalWrite(led4, LOW);
            digitalWrite(led5, LOW);
            digitalWrite(led6, LOW);
            digitalWrite(led7, LOW);
            digitalWrite(led8, LOW);
          state = ON;
        }
      else if(voltage < 254){
        digitalWrite(led, HIGH);
            digitalWrite(led2, HIGH);
            digitalWrite(led3, LOW);
            digitalWrite(led4, LOW);
            digitalWrite(led5, LOW);
            digitalWrite(led6, LOW);
            digitalWrite(led7, LOW);
            digitalWrite(led8, LOW);
          state = ON;
      }
      else if(voltage < 381){
        digitalWrite(led, HIGH);
            digitalWrite(led2, HIGH);
            digitalWrite(led3, HIGH);
            digitalWrite(led4, LOW);
            digitalWrite(led5, LOW);
            digitalWrite(led6, LOW);
            digitalWrite(led7, LOW);
            digitalWrite(led8, LOW);
          state = ON;
      }
      else if(voltage < 508){
        digitalWrite(led, HIGH);
            digitalWrite(led2, HIGH);
            digitalWrite(led3, HIGH);
            digitalWrite(led4, HIGH);
            digitalWrite(led5, LOW);
            digitalWrite(led6, LOW);
            digitalWrite(led7, LOW);
            digitalWrite(led8, LOW);
          state = ON;
      }
      else if(voltage < 635){
        digitalWrite(led, HIGH);
            digitalWrite(led2, HIGH);
            digitalWrite(led3, HIGH);
            digitalWrite(led4, HIGH);
            digitalWrite(led5, HIGH);
            digitalWrite(led6, LOW);
            digitalWrite(led7, LOW);
            digitalWrite(led8, LOW);
          state = ON;
      }
      else if(voltage < 762){
        digitalWrite(led, HIGH);
            digitalWrite(led2, HIGH);
            digitalWrite(led3, HIGH);
            digitalWrite(led4, HIGH);
            digitalWrite(led5, HIGH);
            digitalWrite(led6, HIGH);
            digitalWrite(led7, LOW);
            digitalWrite(led8, LOW);
          state = ON;
      }
      else if(voltage < 889){
        digitalWrite(led, HIGH);
            digitalWrite(led2, HIGH);
            digitalWrite(led3, HIGH);
            digitalWrite(led4, HIGH);
            digitalWrite(led5, HIGH);
            digitalWrite(led6, HIGH);
            digitalWrite(led7, HIGH);
            digitalWrite(led8, LOW);
          state = ON;
      }
      else if(voltage < 1024){
        digitalWrite(led, HIGH);
            digitalWrite(led2, HIGH);
            digitalWrite(led3, HIGH);
            digitalWrite(led4, HIGH);
            digitalWrite(led5, HIGH);
            digitalWrite(led6, HIGH);
            digitalWrite(led7, HIGH);
            digitalWrite(led8, HIGH);
          state = ON;
      }
      break;
    
    case OFF:
    if(voltage < 31){
        
        state = OFF;
    }
    else{
      state = ON;
    }
    break;
    
    default:
    break;
      
  }
}


void setup(){

  pinMode(potPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  Serial.begin(9600);
  
}

void loop()
{
  state = Start;
  
  while(1){
  voltage = analogRead(A5);
    Serial.println(voltage);
    Tick();
  }
}
