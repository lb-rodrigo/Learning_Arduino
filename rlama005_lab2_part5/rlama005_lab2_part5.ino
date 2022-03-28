// C++ code
//

const int LEDpin2 = 2;
const int LEDpin3 = 3;
int buttonA0 = A0;
int buttonA1 = A1;

void setup()
{
  pinMode(LEDpin2, OUTPUT);
  pinMode(LEDpin3, OUTPUT);
  //pinMode(buttonA0, INPUT);
  //pinMode(buttonA1, INPUT);
}

void loop()
{ 

  //buttonA0 = analogRead(A0);
  //buttonA1 = analogRead(A1);   

   if( (digitalRead(buttonA0) == HIGH) && (digitalRead(buttonA1) ==  HIGH)){
    digitalWrite(LEDpin2, HIGH);
    digitalWrite(LEDpin3, HIGH);
  }
  else if(digitalRead(buttonA0) == HIGH){
    digitalWrite(LEDpin2, LOW);
  }
  else if(digitalRead(buttonA1) == HIGH){
    digitalWrite(LEDpin3, LOW);
  }
  else{
    digitalWrite(LEDpin2, HIGH);
    digitalWrite(LEDpin3, HIGH);   
   }

  delay(100);
/*  
  if( (digitalRead(A0) == HIGH) && (digitalRead(A1) ==  HIGH)){
    digitalWrite(LEDpin2, LOW);
    digitalWrite(LEDpin3, LOW);
  }
  else if(digitalRead(A0) == HIGH){
    digitalWrite(LEDpin2, LOW);
  }
  else if(digitalRead(A1) == HIGH){
    digitalWrite(LEDpin3, LOW);
  }
  else{
    digitalWrite(LEDpin2, HIGH);
    digitalWrite(LEDpin3, HIGH);   
   }
  
*/  
}
