// C++ code
//
typedef struct task {
  int state;
  unsigned long period;
  unsigned long elapsedTime;
  int (*TickFct)(int);
} task;

const int LED = 2;
const int LED2 = 3;
const int LED3 = 4;
const int LED4 = 5;
const int LED5 = 6;

const int LED6 = 7;
const int LED7 = 8;
const int LED8 = 9;
const int LED9 = 10;
const int LED10 = 11;


const unsigned short tasksNum = 2;
task tasks[tasksNum];

enum PL_States { Start, ONE_PRESS, TWO_PRESS, THREE_PRESS, 
                    FOUR_PRESS, FIVE_PRESS };

int TickFct_PlinkLed(int state) { 
  
  switch(state){
    case Start:
      state = ONE_PRESS;
      break;
    
    case ONE_PRESS:
      digitalWrite(LED, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
      state = TWO_PRESS;
      break;
    
    case TWO_PRESS:
    
      digitalWrite(LED3, HIGH);
      digitalWrite(LED, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED5, LOW);
    digitalWrite(LED4, HIGH);
      state = THREE_PRESS;
      break;
    
    case THREE_PRESS:
      digitalWrite(LED, HIGH);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED3, LOW);
        digitalWrite(LED2, LOW);
      state = FOUR_PRESS;
      break;
    
    case FOUR_PRESS:
      digitalWrite(LED, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED3, HIGH);
        digitalWrite(LED2, LOW);
      state = FIVE_PRESS;
      break;
    
    case FIVE_PRESS:
      digitalWrite(LED, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED2, HIGH);
    digitalWrite(LED4, HIGH);
      state = ONE_PRESS;
      break;
  }
  
  return state; }

  enum PL2_States { Start2, ONE2_PRESS, TWO2_PRESS, THREE2_PRESS, 
                    FOUR2_PRESS, FIVE2_PRESS};

  int TickFct_P2linkLed(int state){ 
      
      switch(state){
    case Start2:
      state = ONE2_PRESS;
      break;
    
    case ONE2_PRESS:
      digitalWrite(LED6, LOW);
      digitalWrite(LED7, LOW);
      digitalWrite(LED8, LOW);
      digitalWrite(LED9, HIGH);
    digitalWrite(LED10, HIGH);
      state = TWO2_PRESS;
      break;
    
    case TWO2_PRESS:
    
      digitalWrite(LED8, LOW);
      digitalWrite(LED6, HIGH);
      digitalWrite(LED7, LOW);
      digitalWrite(LED10, HIGH);
    digitalWrite(LED9, LOW);
      state = THREE2_PRESS;
      break;
    
    case THREE2_PRESS:
      digitalWrite(LED6, LOW);
      digitalWrite(LED9, HIGH);
      digitalWrite(LED10, LOW);
      digitalWrite(LED8, HIGH);
        digitalWrite(LED7, HIGH);
      state = FOUR2_PRESS;
      break;
    
    case FOUR2_PRESS:
      digitalWrite(LED6, HIGH);
      digitalWrite(LED9, HIGH);
      digitalWrite(LED10, HIGH);
      digitalWrite(LED8, LOW);
        digitalWrite(LED7, HIGH);
      state = FIVE2_PRESS;
      break;
    
    case FIVE2_PRESS:
      digitalWrite(LED6, HIGH);
      digitalWrite(LED8, HIGH);
      digitalWrite(LED10, LOW);
      digitalWrite(LED7, LOW);
    digitalWrite(LED9, LOW);
      state = ONE2_PRESS;
      break;
  }
      
      return state;}


void setup() {
  
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);
  pinMode(LED8, OUTPUT);
  pinMode(LED9, OUTPUT);
  pinMode(LED10, OUTPUT);
  
  unsigned char i = 0;
  tasks[i].state = Start;
  tasks[i].period = 1000;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &TickFct_PlinkLed;
  i++;
  tasks[i].state = Start2;
  tasks[i].period = 500;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &TickFct_P2linkLed;
  

}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned char i;
  for (i = 0; i < tasksNum; ++i) {
    if ( (millis() - tasks[i].elapsedTime) >= tasks[i].period) {
        tasks[i].state = tasks[i].TickFct(tasks[i].state);
        tasks[i].elapsedTime = millis(); // Last time this task was ran
    }
  }
  delay(500);
}
