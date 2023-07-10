#include <stdio.h>
#define n 10

int main() {

  struct aluno
  {
    float notaprova;
    float notatrabalho;
    float media;
    char nome[20];
  } aluno[n];

  int i;
  
 for(i=0; i<n; i++)
 {
    printf("\nDigite o nome do aluno: ");
    scanf("%s", aluno[i].nome);
    printf("\nDigite a nota da prova do aluno: ");
    scanf("%f", &aluno[i].notaprova);
    printf("\nDigite a nota do trabalho do aluno: ");
    scanf("%f", &aluno[i].notatrabalho);

    aluno[i].media=(aluno[i].notaprova+aluno[i].notatrabalho)/2;
    
    printf("\nNome: %s", aluno[i].nome);
    printf("\nNota da prova: %.2f", aluno[i].notaprova);
    printf("\nNota do trabalho: %.2f", aluno[i].notatrabalho);
    printf("\nMédia: %.2f\n", aluno[i].media);
}

  return 0;
}