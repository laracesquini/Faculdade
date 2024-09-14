#include "hibrido.h" //preciso incluir a biblioteca.h pra interfaciar com a função .S

void setup() {

  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);

  asmfunc(); //onde chama a função em linguagem de montagem
 
}

void loop() {
 
}

