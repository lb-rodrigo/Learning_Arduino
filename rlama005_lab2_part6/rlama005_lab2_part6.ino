// C++ code
//
    const int b0 = 2;
    const int b1 = 3;
    const int b2 = 4;
    const int b3 = 5;
    const int b4 = 6;
    const int b5 = 7;
    const int b6 = 8;
    const int b7 = 9;
  int a = 0x00;
  int a0, a1, a2, a3, a4, a5, a6, a7;
  void setup(){
    
    pinMode(b0, OUTPUT);
    pinMode(b1, OUTPUT);
    pinMode(b2, OUTPUT);
    pinMode(b3, OUTPUT);
    pinMode(b4, OUTPUT);
    pinMode(b5, OUTPUT);
    pinMode(b6, OUTPUT);
    pinMode(b7, OUTPUT);
    Serial.begin(9600);
}
  void readData(){
    
    if(Serial.available()){
      a = Serial.parseInt();
  }
    
  a7 = a >> 7;
  a6 = (a >> 6) & 0x01;
  a5 = (a >> 5) & 0x01;
  a4 = (a >> 4) & 0x01;
  a3 = (a >> 3) & 0x01;
  a2 = (a >> 2) & 0x01;
  a1 = (a >> 1) & 0x01;
  a0 = (a >> 0) & 0x01;
}
  void resetB()
{
    digitalWrite(b7,LOW);
    digitalWrite(b6,LOW);
    digitalWrite(b5,LOW);
    digitalWrite(b4,LOW);
    digitalWrite(b3,LOW);
    digitalWrite(b2,LOW);
    digitalWrite(b1,LOW);
    digitalWrite(b0,LOW);
}
  void writeToB(unsigned char temp){
      
  if ((temp>>7) & 0x01){digitalWrite(b7,HIGH);}
  if ((temp>>6) & 0x01){digitalWrite(b6,HIGH);}
  if ((temp>>5) & 0x01){digitalWrite(b5,HIGH);}
  if ((temp>>4) & 0x01){digitalWrite(b4,HIGH);}
  if ((temp>>3) & 0x01){digitalWrite(b3,HIGH);}
  if ((temp>>2) & 0x01){digitalWrite(b2,HIGH);}
  if ((temp>>1) & 0x01){digitalWrite(b1,HIGH);}
  if (temp & 0x01){digitalWrite(b0,HIGH);}
}
void loop(){
  
  readData();
  resetB();
    
    if(a <= 0x04)
  digitalWrite(b6, HIGH);
  
  if((a == 0x01) || (a == 0x02)){
      digitalWrite(b5, HIGH);
  }
  else if((a == 0x03) || (a == 0x04)){
      digitalWrite(b5, HIGH);
      digitalWrite(b4, HIGH);
  }
  else if((a == 0x05) || (a == 0x06)){
      digitalWrite(b5, HIGH);
      digitalWrite(b4, HIGH);
      digitalWrite(b3, HIGH);
  }
  else if((a == 0x07) || (a == 0x08) ||(a == 0x09)){
      digitalWrite(b5, HIGH);
      digitalWrite(b4, HIGH);
      digitalWrite(b3, HIGH);
      digitalWrite(b2, HIGH);
  }
  else if((a == 0x0a) || (a == 0x0b) ||(a == 0x0c)){
      digitalWrite(b5, HIGH);
      digitalWrite(b4, HIGH);
      digitalWrite(b3, HIGH);
      digitalWrite(b2, HIGH);
      digitalWrite(b1, HIGH);
  }
  else if((a == 0x0e) || (a == 0x0f) ||(a == 0x0d)){
      digitalWrite(b5, HIGH);
      digitalWrite(b4, HIGH);
      digitalWrite(b3, HIGH);
      digitalWrite(b2, HIGH);
      digitalWrite(b1, HIGH);
      digitalWrite(b0, HIGH);
  }
    
 delay(1000);
}
