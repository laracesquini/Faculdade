#include <stdio.h>

int main ()
{
  int N;

  printf("Digite um número: ");
  scanf("%d", &N);
  if(N>20 && N<100)
    printf("\nO número %d está no intervalo entre 20 e 100", N);
  else
    printf("\nO número %d está  fora do intervalo.", N);

  return 0;
}