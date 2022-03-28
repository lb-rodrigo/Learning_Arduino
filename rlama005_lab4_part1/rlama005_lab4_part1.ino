// C++ code
//
enum State{Start, LED1_BLINK, LED2_BLINK, LED3_BLINK}state;

int LED1 = 0;
int LED2 = 1;
int LED3 = 2;


void Tick(){
  switch(state){
  case Start:
    
    state = LED1_BLINK;
    break;
//////////BLCIK 1////////////
    
    case LED1_BLINK:
    
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      //delay(1000);
    
      state = LED2_BLINK;
    break;
//////////BLCIK 2////////////    
    case LED2_BLINK:
    
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
      //delay(1000);
      
      state = LED3_BLINK;
    break;
//////////BLCIK 3////////////    
    case LED3_BLINK:
    
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      //delay(1000);
    
      state = LED1_BLINK;
    break;
    
  }
}

void setup()
{
  pinMode(LED1, OUTPUT);    
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop(){

  state = Start;
  while(1){
    Tick();
    delay(1000);
  }

  
}
