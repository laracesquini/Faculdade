#include <stdio.h>

int main()
{
  //Declaração de variáveis
  int A[10], B[10], i, j=0, count=0;

  //Programa principal
  for(i=0; i<10; i++)
    {
      printf("\nDigite um valor: ");
      scanf("%d", &A[i]);
      if(A[i]>0)
      {
        B[j]=A[i];
        j++;
        count++;
      }
    }

  printf("\nVetor A: ");
  for(i=0; i<10; i++)
    printf(" %d", A[i]);
  printf("\nVetor B: ");
  for(j=0; j<count; j++)
    printf(" %d", B[j]);

  return 0;
}
