#include <AFMotor.h> //THIS LIBRARY ALLOWS THE CODE TO CONTROL THE DC MOTORs IN WALL-E
////https://learn.adafruit.com/adafruit-motor-shield/library-install 
#include <NewPing.h> // THIS LIBRARY ALLOWS THE CODE TO CONTROL  THE ULTRASONIC SENSOR IN WALL-E
////https://github.com/livetronic/Arduino-NewPing
#include <Servo.h> // THIS LIBRARY ALLOWS THE CODE TO CONTROL THE SERVO MOTOR IN WALL-E
////https://github.com/arduino-libraries/Servo.git

typedef struct task {
  int state;
  unsigned long period;
  unsigned long elapsedTime;
  int (*TickFct)(int);
} task;

////SETTING UP THE ULTRASONIC SENSOR////
int trig_pin = A0;
int echo_pin = A1;
int max_cm_distance = 200;

NewPing sonar(trig_pin, echo_pin, max_cm_distance);

////SETTING UP SERVO MOTOR////
Servo Wall_E;

///OTHER VARIABLES////
int max_speed = 150;
int delays = 0;
int Wall_E_Speed = 0;

int dist_left = 0;
int dist_right = 0;
int distance = 100;

bool forward = false;
bool right = false;
bool left = false;
bool back = false;

////////////////INTITIALIZING WALL-E MOTORS//////////////////
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);


////////CONCURRENT STATE MACHINE//////////
const unsigned short tasksNum = 2;
task tasks[tasksNum];

enum BL_States { START, MOVE_FORWARD, STOP, BACKWARDS, LOOK_LEFT, LOOK_RIGHT, ADJUST,
                 TURN_RIGHT, TURN_LEFT};
enum Ping_States {START2, readPing};

int TickFct_MOVE(int state) { 
  switch(state){
    case START:
      state = MOVE_FORWARD;
      break;

     case MOVE_FORWARD:
      dist_left = 0;
      dist_right = 0;
            
            motor1.setSpeed(max_speed);
            motor2.setSpeed(max_speed);
      motor1.run(FORWARD);
      motor2.run(FORWARD);
       ///maybe some for loop//
      
      if(distance <= 15){
        forward = false;
        state = STOP;
        }
       else{
        forward = true;
        state = MOVE_FORWARD;
       }

      break;

     case STOP:
        
       motor1.run(RELEASE);
       motor2.run(RELEASE);
       delays = 0;
       state = BACKWARDS;
       break;
     
     case BACKWARDS:
            motor1.setSpeed(max_speed);
            motor2.setSpeed(max_speed);
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
        if(delays > 3){
            delays = 0;
            state = LOOK_RIGHT;
          }
       break;
       
     case LOOK_RIGHT:
        Wall_E.write(50);
         if(delays > 5){
           delays = 0;
            dist_right = distance;
            Wall_E.write(115);
            state = LOOK_LEFT;
          }
         break;

      case LOOK_LEFT:
        Wall_E.write(170);
          if(delays > 5){
           delays = 0;
           dist_left = distance;
           Wall_E.write(115);
           state = ADJUST; 
           }
         break;

       case ADJUST:
        if(dist_right >= dist_left){
            delays = 0;
            state = TURN_RIGHT;
          }
        else{
          delays = 0;
          state = TURN_LEFT;
          }
        break;

        case TURN_LEFT:
            motor1.setSpeed(max_speed);
            motor2.setSpeed(max_speed);
          motor1.run(BACKWARD);
          motor2.run(FORWARD);
          if(delays > 4){
            state = MOVE_FORWARD;
           }
         break;
         case TURN_RIGHT:
            motor1.setSpeed(max_speed);
            motor2.setSpeed(max_speed);
          motor1.run(FORWARD);
          motor2.run(BACKWARD);
          if(delays > 4){
            state = MOVE_FORWARD;  
          }
    }
  return state; }



int PingTick_Func(int state){
  switch(state){
    case START2:
      state = readPing;
      break;

     case readPing:
      distance = sonar.ping_cm();
      if(distance == 0){
          distance = 250;
        }
      break;
    }
  return state;}

void setup() {
  Wall_E.attach(10);
  Wall_E.write(115);
  unsigned char i = 0;
  
  tasks[i].state = START;
  tasks[i].period = 100;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &TickFct_MOVE;
    i++;
  tasks[i].state = START2;
  tasks[i].period = 100;
  tasks[i].elapsedTime = 0;
  tasks[i].TickFct = &PingTick_Func;
}

void loop() {
  // put your main code here, to run repeatedly:

  delays++;
  unsigned char i;
  for (i = 0; i < tasksNum; ++i) {
    if ( (millis() - tasks[i].elapsedTime) >= tasks[i].period) {
        tasks[i].state = tasks[i].TickFct(tasks[i].state);
        tasks[i].elapsedTime = millis(); // Last time this task was ran
    }
  }
  delay(100);
}
