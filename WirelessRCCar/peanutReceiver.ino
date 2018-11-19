#include "receiver.h"
#define IN3 3
#define IN4 4
#define IN1 10
#define IN2 9
#define ENRIGHT 6
#define ENLEFT 5

float rVal = 0;
float speedy = 0;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENLEFT, OUTPUT);
  pinMode(ENRIGHT, OUTPUT);
  
  Serial.begin(9600);
  receiver_setup();
}

void loop() {
  // put your main code here, to run repeatedly:
  if(receiving(rVal))
  {
    
    if(rVal>0 && rVal < 90){                  //forward 
      speedy = map(rVal, 90, 0 , 0, 255);
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);      
      analogWrite(ENLEFT, speedy);
      analogWrite(ENRIGHT, speedy);
    }
    if(rVal == -2){                  //right turn = -2
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENLEFT, 110);
      analogWrite(ENRIGHT, 110);
    }
    if(rVal == -3){                  //left turn = -3
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, HIGH);
      analogWrite(ENLEFT, 110);
      analogWrite(ENRIGHT, 110);
      }
   if(rVal>190){                  //backwards
      speedy = map(rVal, 170, 0 , 0, 255);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENLEFT, speedy);
      analogWrite(ENRIGHT, speedy);
    }
    if(rVal == -5){                  //stop = 5
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, HIGH);
      speedy = 0;
      analogWrite(ENLEFT, speedy);
      analogWrite(ENRIGHT, speedy);
    }

//       Serial.println("speedy:");
//      Serial.println(speedy);
//    Serial.print("I received: ");
//    Serial.println(rVal);
  }//end if

}
