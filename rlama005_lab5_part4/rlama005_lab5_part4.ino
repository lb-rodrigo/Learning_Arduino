// C++ code
//
enum States{Start, ON, OFF}state;
int potPin = A5;
int voltage; 

int led = 2;


void Tick(){
  
  switch(state){
    case Start:
      state = OFF;
      break;
       
    case ON:
        if(voltage >= 200){
        digitalWrite(led, HIGH);
          state = ON;
      }
      else if (voltage < 200){
        digitalWrite(led, LOW);
        state = OFF;
        }
      break;
    
    case OFF:
     if(voltage < 200){
        digitalWrite(led, LOW);
        state = OFF;
    }
    else if(voltage >= 200){
      digitalWrite(led, HIGH);
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
