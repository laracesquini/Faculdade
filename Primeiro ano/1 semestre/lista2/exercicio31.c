#include <stdio.h>

int main()
{
  const int d=18;
  const int a=70;
  int idade;

  printf("Digite sua idade: ");
  scanf("%d", &idade);
  if(idade>=d)
  { 
    printf("\nVocê pode dirigir!");
  }
  else
  {
    printf("\nVocê não pode dirigir :(");
  }
  if(idade>=a)
  {
    printf("\nVocê tem idade para se aposentar!");
  }
  else
  {
    printf("\nVocê ainda não tem idade para se aposentar");
    }

  return 0;
}