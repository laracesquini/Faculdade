#include <stdio.h>

int main() {

  //Declaração de variáveis
  int A[10], B[10], C[10], D[10], i, j, k=0, l=0, somaA=0, somaB=0;

  //Programa principal
  //item a
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
  printf("\nVetor A: ");
  for(i=0; i<10; i++)
    printf(" %d", A[i]);
  printf("\nVetor B: ");
  for(j=0; j<10; j++)
    printf(" %d", B[j]);

  //item b
  for(i=0; i<10; i++)
    somaA=somaA+A[i];
  for(j=0; j<10; j++)
    somaB=somaB+B[j];

  printf("\nSoma de A: %d", somaA);
  printf("\nSoma de B: %d", somaB);

  //item c
  j=0;
  for(i=0; i<10; i++)
    {
      C[k]=A[i]+B[j];
      k++;
      j++;
    }
  printf("\nSoma de A e B: ");
  for(k=0; k<10; k++)
    printf(" %d", C[k]);

  //item d
  i=0;
for(j=0; j<10; j++)
  {
    D[l]=B[j]-A[i];
    l++;
    i++;
  }
  printf("\nSubtração de B e A: ");
  for(l=0; l<10; l++)
    printf(" %d", D[l]);

  return 0;
  
}