#include <stdio.h>

int main()
{
  int a, b;

  printf("Digite um número: ");
  scanf("%d", &a);

  b=a%2;
  
  if(b==0)
    printf("\nEsse número é par");
  else
    printf("\nEsse número é ímpar");

  return 0;
}