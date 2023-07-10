#include <stdio.h>

int main() {

  //Declaração de variáveis
  int A[10], B[10], C[10], i, j, k=0;

  //Programa principal
  for(i=0; i<10; i++)
    {
      printf("\nDigite um valor para A: ");
      scanf("%d", &A[i]);
    }
  for(j=0; j<10; j++)
    {
      printf("\nDigite um valor para B: ");
      scanf("%d", &B[j]);
    }
  j=0;
  for(i=0; i<10; i++)
    {
      C[k]=A[i]*B[j];
      k++;
      j++;
        
    }
  printf("\nVetor A: ");
  for(i=0; i<10; i++)
    printf(" %d", A[i]);
  printf("\nVetor B: ");
  for(j=0; j<10; j++)
    printf(" %d", B[j]);
  printf("\nVetor C: ");
  for(k=0; k<10; k++)
    printf(" %d", C[k]);
    
    return 0;
}