#include <stdio.h>

void troca(int *end1, int *end2)
{
  int aux;
  aux = *end1;
  *end1 = *end2;
  *end2 = aux;
}

int main()
{
  int n, n1;

  printf("\nDigite um número: ");
  scanf("%d", &n);
  printf("\nDigite outro número: ");
  scanf("%d", &n1);
  printf("\nValor 1: %d", n);
  printf("\nValor 2: %d", n1);
  troca(&n, &n1);
  printf("\n\nAPÓS A TROCA: ");
  printf("\n\nValor 1: %d", n);
  printf("\nValor 2: %d", n1);

  return 0;
}