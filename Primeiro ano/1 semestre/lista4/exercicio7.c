#include <stdio.h>

int main()
{
  int N, i, resultado;

  printf("Digite um número: ");
  scanf("%d", &N);

  i=1;

  while(i<=10) 
  {
    resultado=i*N;
    printf("\n%d x %d = %d",N, i, resultado);
    i++;
    }

  return 0;
}
