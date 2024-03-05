#include <Arduino.h>

int trigger = 2;
int echo = 3;
int media;

void setup() {
 
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  
  long duration, inches, cm, plus=0;

  for (int i=0; i<3; i++){
  
    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(5);
    digitalWrite(trigger, LOW);

  //pulseIn is a function to read a pulse duration
    duration = pulseIn(echo, HIGH);

    plus = plus + duration;
    
    delay(100);
  }

  plus = plus / 3;

  inches = plus / 74 / 2;
  cm = plus / 29 / 2;

  Serial.print(" inches: ");
  Serial.print(inches);
  Serial.print(" cm: ");
  Serial.print(cm);
  
  Serial.println();

}

