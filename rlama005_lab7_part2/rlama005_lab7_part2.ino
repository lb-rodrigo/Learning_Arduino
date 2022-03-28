#include <LiquidCrystal.h>


typedef struct task {
  int state;
  unsigned long period;
  unsigned long elapsedTime;
  int (*TickFct)(int);
} task;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int button = A0;
int button2 = A1;
int button3 = A2;
long int distance = 0;

char raceTrack[2][16];
char raceCar = '>';
char obstacle = '#';
int lastRand = 0;
int num;
int timee = 0;
int clockk = 1000;
int tick = 0;
bool crash = false;


const unsigned short tasksNum = 3;
task tasks[tasksNum];

enum PERIOD_States {Start3, DECREASE, RESET};
enum RACE_States {Start, RACE ,COLLISION};
enum CAR_States {Start2, UP, DOWN};

//////////////TIME LOGIC////////////////
int TickFct_PERIOD(int state) { 

  switch(state){
    case Start3:
      state = DECREASE;
      break;

     case DECREASE:

    if(crash == true){
      state = RESET;
      }
        
    tick++;
    if(tick == 40){
      if(clockk >= 200){
        clockk = clockk - 100;
        tasks[0].period = clockk;
        //tasks[1].period = clockk;
        tick = 0;
       }
      }
     break;
    
    case RESET:
      if(digitalRead(button3) == HIGH){
        clockk = 1000; 
        tasks[0].period = clockk; 
        tick = 0; 
        crash = false;
        state = DECREASE;
      }
      else{
        state = RESET;
        }
      break;
   }
  
  return state;
  }
/////////RACE CAR LOGIC//////////
int TickFct_CAR(int state){
  switch(state){
    
    case Start2:
      raceTrack[0][0] = raceCar;  
      state = UP;
      break;
    
    case UP:
      if (crash == true){
          timee++;
          if(timee == 50){
            timee = 0;
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Distance:");
            lcd.setCursor(0,1);
            lcd.print(distance);
           }
        }
      if(digitalRead(button2) == HIGH){
          raceTrack[1][0] = raceCar;
            raceTrack[0][0] = ' ';
            state = DOWN;
        }
      else{
        state = UP;
      }
      break;
    case DOWN:

          if (crash == true){
          timee++;
          if(timee == 50){
            timee = 0;
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("Distance:");
            lcd.setCursor(0,1);
            lcd.print(distance);
           }
        }
      if(digitalRead(button) ==  HIGH){
          raceTrack[0][0] = raceCar;
            raceTrack[1][0] = ' ';
            state = UP;
        }
      else{
        state = DOWN;
      }
      break;
  }
  
  return state;}

//////////RACE LOGIC//////////////
int TickFct_RACE(int state) { 
  
  switch(state){
  
    case Start:
      for(int i = 0; i < 2; i++){
          for(int j = 0; j < 16; j++){
            raceTrack[i][j] = ' ';
          }
        }
      raceTrack[0][0] = raceCar;
      state = RACE;
      break;
    
    case RACE:
    
    lcd.setCursor(0,0);
    lcd.print(raceTrack[0]);
  
  lcd.setCursor(0,1);
    lcd.print(raceTrack[1]);
  
  num = random(4);
  if (num == 0) {
    if(raceTrack[1][14] ==  obstacle){
      raceTrack[0][15] = ' ';
      raceTrack[1][15] = ' '; 
    }
    else {
      raceTrack[0][15] = obstacle;
      raceTrack[1][15] = ' ';
    }
  } 
  else if (num == 1) {
    if(raceTrack[0][14] ==  obstacle){
      raceTrack[0][15] = ' ';
      raceTrack[1][15] = ' '; 
    }
    else{
      raceTrack[0][15] = ' ';
      raceTrack[1][15] = obstacle;
    }
  } 
  else {
    raceTrack[0][15] = ' ';
    raceTrack[1][15] = ' ';
  }

  if(digitalRead(button3) == HIGH){
      //raceTrack[r][0] = 'X';
      //   lcd.setCursor(0,r); 
      //   lcd.print(raceTrack[r][0]);
         //crash = true;
//         timee = 0;
           distance = 0;
         state = Start;
    }
    for(int r = 0; r < 2; r++){
        if((raceTrack[r][0] == raceCar)&&
         (raceTrack[r][1] != ' ')){
         raceTrack[r][0] = 'X';
         lcd.setCursor(0,r); 
         lcd.print(raceTrack[r][0]);
         crash = true;
         
         state = COLLISION;
        }
    }
    
    for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 15; j++) {
      if(raceTrack[i][j] != raceCar){
        raceTrack[i][j] = raceTrack[i][j + 1];
        distance++;
      }
    }
  }
    
      break;
    
    case COLLISION:
      //if(time == 29){
      /*    time = 0;
          lcd.clear();
            lcd.setCursor(0,0);
          lcd.print("Distance:");
            lcd.setCursor(0,1);
            lcd.print(distance); */
        //}
        //else{ time++;}
      if(digitalRead(button3) == HIGH){
                distance = 0;
                //clockk  = 1000;
              //  tasks[0].period = clockk;
              state = Start;
            }
      break;
  }
  
  return state; }
/////////////////////////////////

void setup() {
  lcd.begin(16, 2);
  pinMode(button, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  
  unsigned char i = 0;
  tasks[i].state = Start;
  tasks[i].period = clockk;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &TickFct_RACE;
   i++;
  tasks[i].state = Start2;
  tasks[i].period = 50;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &TickFct_CAR;
    i++;
  tasks[i].state = Start3;
  tasks[i].period = 100;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &TickFct_PERIOD;
  
}

void loop() {
 // 1000 = 500 = 0
 
  // put your main code here, to run repeatedly:
  unsigned char i;
  for (i = 0; i < tasksNum; ++i) {
    if ( (millis() - tasks[i].elapsedTime) >= tasks[i].period) {
        tasks[i].state = tasks[i].TickFct(tasks[i].state);
        tasks[i].elapsedTime = millis(); // Last time this task was ran
    }
  }
  delay(50);
}
