#include "asmfunc.h"

int pino_motor = 8;
int botao3 = 5;
int botao2 = 6;
int botao1 = 7;

void setup() {
  // put your setup code here, to run once:
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);

  asmfunc();
}

void setup()
{
  pinMode(pino_motor, OUTPUT);
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);
  pinMode(botao3, INPUT);
}

void loop()
{
  int estadoBotao1 = digitalRead(botao1);
  int estadoBotao2 = digitalRead(botao2);
  int estadoBotao3 = digitalRead(botao3);

  if (estadoBotao1 == 1) {
    digitalWrite(pino_motor, HIGH);
    delay(1000);
  } 
  else if(estadoBotao2 == 1){
    digitalWrite(pino_motor, HIGH);
    delay(5000);
  }
  else if(estadoBotao3 == 1){
    digitalWrite(pino_motor, HIGH);
    delay(10000);
  }
  else{
    digitalWrite(pino_motor, LOW);
  }
}