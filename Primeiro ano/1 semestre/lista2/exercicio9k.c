#include <stdio.h>

int main()
{
  int N1, N, N2;

  printf("Digite um número inteiro: ");
  scanf("%d", &N);
  N1=N-1;
  N2=N+1;
  printf("\nO antecessor desse número é %d e o sucessor dele é %d", N1, N2);
  
  return 0;
}