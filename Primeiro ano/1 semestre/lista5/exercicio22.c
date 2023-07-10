#include <stdio.h>
#include <string.h>

int main() 
{
  char nome[40];
  int i=0, j=0;

  printf("\nDigite seu nome: ");
  scanf("%[^\n]s", nome);

  while(nome[i]!='\0')
    {
    printf(" %c", nome[i]);
    printf("\n");
      i++;
      j++;
    }
  printf("\nO total de algarismos é %d", j);

  return 0;
}