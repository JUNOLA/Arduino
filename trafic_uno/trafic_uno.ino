#include <HL1606stripPWM.h>

int vert1=0;
int orange1=1;
int rouge1=2;
int vert2=3;
int orange2=4;
int rouge2=5;

void setup() {
  pinMode(vert1,OUTPUT);
  pinMode(orange1,OUTPUT);
  pinMode(rouge1,OUTPUT);
  pinMode(vert2,OUTPUT);
  pinMode(orange2,OUTPUT);
  pinMode(rouge2,OUTPUT);
}

void loop() {
  digitalWrite(vert1,HIGH);
  digitalWrite(rouge2,HIGH);
  delay(1000);
  digitalWrite(vert1,LOW);
  digitalWrite(orange1,HIGH);
  delay(200);
  digitalWrite(orange1,LOW);
  delay(200);
    digitalWrite(orange1,HIGH);
  delay(200);
  digitalWrite(orange1,LOW);
  delay(200);
  digitalWrite(rouge2,LOW);
  digitalWrite(vert2,HIGH);
  digitalWrite(rouge1,HIGH);
  delay(1000);
  digitalWrite(vert2,LOW);
  digitalWrite(orange2,HIGH);
  delay(200);
  digitalWrite(orange2,LOW);
  delay(200);
   digitalWrite(orange2,HIGH);
  delay(200);
  digitalWrite(orange2,LOW);
  delay(200);
  digitalWrite(rouge1,LOW);
}
