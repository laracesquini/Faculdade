#include <stdio.h>

int main() {

  struct aluno
  {
    float notaprova;
    float notatrabalho;
    float media;
    char nome[20];
  }aluno1;

  printf("\nDigite o nome do aluno: ");
  scanf("%s", aluno1.nome);
  printf("\nDigite a nota da prova do aluno: ");
  scanf("%f", &aluno1.notaprova);
  printf("\nDigite a nota do trabalho do aluno: ");
  scanf("%f", &aluno1.notatrabalho);

  aluno1.media=(aluno1.notaprova+aluno1.notatrabalho)/2;
  
  printf("\nNome: %s", aluno1.nome);
  printf("\nNota da prova: %.2f", aluno1.notaprova);
  printf("\nNota do trabalho: %.2f", aluno1.notatrabalho);
  printf("\n%.2f", aluno1.media);
  
  return 0;
}