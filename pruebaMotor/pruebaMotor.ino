#include "Maxbotix.h"

const int motorPin1=8;
const int motorPin2=9;
const int motorPin3=6;
const int motorPin4=7;
const int motorPinEn12=2;
const int motorPinEn34=3;
long cm;

void setup() {
  pinMode(motorPin1,OUTPUT);
  pinMode(motorPin2,OUTPUT);
  pinMode(motorPin3,OUTPUT);
  pinMode(motorPin4,OUTPUT);
  pinMode(4,INPUT);
  pinMode(A0,INPUT);
  Serial.begin(9600);
}

void loop() {
      long pulse, inches;
      pulse = pulseIn(4, HIGH);
      cm = pulse * 2.54/147;
      Serial.print(cm);
      Serial.print("cm");
      Serial.println();
      Serial.print(analogRead(A0));
      Serial.println();
      if(millis()<50000) {
        if(cm<200){
         
          digitalWrite(motorPin1,LOW);
          digitalWrite(motorPin2,HIGH);
          digitalWrite(motorPin3,LOW);
          digitalWrite(motorPin4,HIGH);
          
          if(cm<15){
            while(cm<15){
              pulse = pulseIn(4, HIGH);
              cm = pulse * 2.54/147;
              digitalWrite(motorPin1,HIGH);
              digitalWrite(motorPin2,LOW);
      
              digitalWrite(motorPin3,HIGH);
              digitalWrite(motorPin4,LOW);  
            }
            delay(500);  
            }
            if(cm<25){
            digitalWrite(motorPin1,LOW);
            digitalWrite(motorPin2,LOW);
            digitalWrite(motorPin3,LOW);
            digitalWrite(motorPin4,LOW);
            }
            
        }
        
        else{
          long t=millis();
          pulse = pulseIn(4, HIGH);
          cm = pulse * 2.54/147;
          while((millis()-t) < 3000 && cm>100){
            pulse = pulseIn(4, HIGH);
            cm = pulse * 2.54/147;
            vueltaIzquierda();  
            delay(150);          
          }
        }
        
      }
      else{
          digitalWrite(motorPin1,LOW);
          digitalWrite(motorPin2,LOW);
          digitalWrite(motorPin3,LOW);
          digitalWrite(motorPin4,LOW);
        }
      
    
}
void vueltaIzquierda(){
  digitalWrite(motorPin1,LOW);
  digitalWrite(motorPin2,LOW);
  digitalWrite(motorPin3,LOW);
  digitalWrite(motorPin4,LOW);
  digitalWrite(motorPin1,LOW);
  digitalWrite(motorPin2,HIGH);
  delay(100); 
  digitalWrite(motorPin1,LOW);
  digitalWrite(motorPin2,LOW);
}

void vueltaDerecha(){
  digitalWrite(motorPin1,LOW);
  digitalWrite(motorPin2,LOW);
  digitalWrite(motorPin3,LOW);
  digitalWrite(motorPin4,LOW);
  delay(500);
  digitalWrite(motorPin3,LOW);
  digitalWrite(motorPin4,HIGH);
  delay(500); 
  digitalWrite(motorPin3,LOW);
  digitalWrite(motorPin4,LOW);
}

