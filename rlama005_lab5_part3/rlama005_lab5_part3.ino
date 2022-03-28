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
      if (voltage < 10){
      
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
      else if(voltage < 50){
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
      else if(voltage < 100){
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
      else if(voltage < 150){
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
      else if(voltage < 200){
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
      else if(voltage < 250){
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
      else if(voltage < 300){
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
      else if(voltage < 350){
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
      else if(voltage < 400){
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
    if(voltage < 10){
        
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
