#include "asmfunc.h"

//definição das conexões dos componentes com o arduíno
int pino_motor = 7;  
int botao1 = 4;      
int botao2 = 5;      
int botao3 = 6;      

void setup()
{
  //definição do motor como saída e dos botões como entrada
  pinMode(pino_motor, OUTPUT);
  pinMode(botao1, INPUT);
  pinMode(botao2, INPUT);
  pinMode(botao3, INPUT);
}

void loop()
{
  //leitura das entradas fornecidas pelos botões
  int estadoBotao1 = digitalRead(botao1);
  int estadoBotao2 = digitalRead(botao2);
  int estadoBotao3 = digitalRead(botao3);
  
  //verifica qual botão foi pressionado e faz a chamada da função em Assembly passando essa informação
  if (estadoBotao1 == 1) {
	asmfunc(1);
  } 
  else if(estadoBotao2 == 1){
	asmfunc(2);
  }
  else if(estadoBotao3 == 1){
	asmfunc(3);
  }
  else{
    digitalWrite(pino_motor, LOW);
  }
}
