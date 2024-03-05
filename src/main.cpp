#include <Arduino.h>

int trigger = 2;
int echo = 3;

void setup() {
 
  Serial.begin(9600);
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  
  long duration, inches, cm;

  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(5);
  digitalWrite(trigger, LOW);

  //pulseIn is a function to read a pulse duration
  duration = pulseIn(echo, HIGH);

  inches = duration / 74 / 2;
  cm = duration / 29 / 2;

  Serial.print("inches: ");
  Serial.print(inches);
  Serial.print(" cm: ");
  Serial.print(cm);
  
  Serial.println();

  delay(100);
  

}

