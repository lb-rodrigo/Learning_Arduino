// C++ code
//
enum States{Start, ONE_REL, ONE_PRESS, TWO_REL, TWO_PRESS, THREE_REL, THREE_PRESS,
           FOUR_REL, FOUR_PRESS, FIVE_REL, FIVE_PRESS}state;

const int LED = 2;
const int LED2 = 3;
const int LED3 = 4;
const int LED4 = 5;
const int LED5 = 6;
int button = A0;


void Tick(){
  switch(state){
    case Start:
    
      state = ONE_REL;
      break;
    case ONE_REL:
    if(digitalRead(button) == HIGH){
        digitalWrite(LED, HIGH);
      
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, HIGH);
      
    digitalWrite(LED5, HIGH);

      state = TWO_PRESS;
    }
    else{
      
      digitalWrite(LED, HIGH);
      
      digitalWrite(LED2, HIGH);
      
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, HIGH);
      
    digitalWrite(LED5, HIGH);
        
      state = ONE_REL;
      
    }
    break;
////////////////PETTERN 2////////////////////////    
    case TWO_PRESS:
    if(digitalRead(button) == HIGH){
      
      digitalWrite(LED3, HIGH);
      digitalWrite(LED, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED5, LOW);
    digitalWrite(LED4, HIGH);
          
      state = TWO_PRESS;
    }
    else{
     
    digitalWrite(LED3, HIGH);
      digitalWrite(LED, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED5, LOW);
    digitalWrite(LED4, HIGH);
          
       
      state = TWO_REL;
      
    }
    break;
    /////////////////////////////////////////////    
    case TWO_REL:
    if(digitalRead(button) == HIGH){
        digitalWrite(LED3, HIGH);
      digitalWrite(LED, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED5, LOW);
    digitalWrite(LED4, HIGH);
      state = THREE_PRESS;
    }
    else{
     
      digitalWrite(LED3, HIGH);
      digitalWrite(LED, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED5, LOW);
    digitalWrite(LED4, HIGH);
        
      state = TWO_REL;
      
    }
    break;
////////////////PETTERN 3////////////////////////    
    case THREE_PRESS:
    if(digitalRead(button) == HIGH){
        digitalWrite(LED, HIGH);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED3, LOW);
        digitalWrite(LED2, LOW);
      state = THREE_PRESS;
    }
    else{
      
      digitalWrite(LED, HIGH);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED3, LOW);
        digitalWrite(LED2, LOW);
      state = THREE_REL;
      
    }
    break;
    /////////////////////////////////////////////    
    case THREE_REL:
    if(digitalRead(button) == HIGH){
        digitalWrite(LED, HIGH);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED3, LOW);
        digitalWrite(LED2, LOW);
      
      state = FOUR_PRESS;
    }
    else{
      digitalWrite(LED, HIGH);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED3, LOW);
        digitalWrite(LED2, LOW);
      state = THREE_REL;
      
    }
    break;
////////////////PETTERN 4////////////////////////    
    case FOUR_PRESS:
    if(digitalRead(button) == HIGH){
        
      digitalWrite(LED, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED3, HIGH);
        digitalWrite(LED2, LOW);
      
          
      state = FOUR_PRESS;
    }
    else{
     
    digitalWrite(LED, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED3, HIGH);
        digitalWrite(LED2, LOW);
      
       
      state = FOUR_REL;
      
    }
    break;
    /////////////////////////////////////////////    
    case FOUR_REL:
    if(digitalRead(button) == HIGH){
        digitalWrite(LED, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED3, HIGH);
        digitalWrite(LED2, LOW);
      

      state = FIVE_PRESS;
    }
    else{
     
      digitalWrite(LED, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED3, HIGH);
        digitalWrite(LED2, LOW);
       
      state = FOUR_REL;
      
    }
    break;
////////////////PETTERN 5////////////////////////    
    case FIVE_PRESS:
    if(digitalRead(button) == HIGH){
        
      digitalWrite(LED, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED2, HIGH);
    digitalWrite(LED4, HIGH);
          
      state = FIVE_PRESS;
    }
    else{
      
      digitalWrite(LED, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED2, HIGH);
    digitalWrite(LED4, HIGH);  
       
      state = FIVE_REL;
      
    }
    break;
    /////////////////////////////////////////////    
    case FIVE_REL:
    if(digitalRead(button) == HIGH){
        
      digitalWrite(LED, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED2, HIGH);
    digitalWrite(LED4, HIGH);
      
      state = ONE_PRESS;
    }
    else{
      
      digitalWrite(LED, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED2, HIGH);
    digitalWrite(LED4, HIGH);
      state = FIVE_REL;
      
    }
    break;
////////////////1 PRESSED////////////////////////    
    case ONE_PRESS:
    if(digitalRead(button) == HIGH){
        
      digitalWrite(LED, HIGH);
      
      digitalWrite(LED2, HIGH);
      
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, HIGH);
      
    digitalWrite(LED5, HIGH);

          
      state = ONE_PRESS;
    }
    else{
      
      digitalWrite(LED, HIGH);
      
      digitalWrite(LED2, HIGH);
      
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, HIGH);
      
    digitalWrite(LED5, HIGH);
  
       
      state = ONE_REL;
      
    }
    break;
  }
}


void setup(){
  
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
}

void loop(){
  
  state = Start;
  while(1){
    Tick();
  }
}
