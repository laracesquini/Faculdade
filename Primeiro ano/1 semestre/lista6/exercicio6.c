#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define n 4

int main() {

  //Declaração de variáveis
  int A[n][n], B[n][n], C[n][n], i, j, maior;

  //Programa principal
  srand(time(NULL));
  
  for(i=0; i<n; i++)
    for(j=0; j<n; j++)
      {
        A[i][j]=1+rand()%100;
        B[i][j]=1+rand()%100;
        if(A[i][j]>B[i][j])
          C[i][j]=A[i][j];
        else
          C[i][j]=B[i][j];
      }
  printf("\nMatriz A: \n");
  for(i=0; i<n; i++)
    {
      for(j=0; j<n; j++)
        {
           printf(" %d", A[i][j]);
        }
      printf("\n");
    }
  printf("\n");
  printf("\nMatriz B: \n");
  for(i=0; i<n; i++)
    {
      for(j=0; j<n; j++)
        {
           printf(" %d", B[i][j]);
        }
      printf("\n");
    }
  printf("\n");
  printf("\nMatriz C: \n");
  for(i=0; i<n; i++)
    {
      for(j=0; j<n; j++)
        {
           printf(" %d", C[i][j]);
        }
      printf("\n");
    }
      
  return 0;
}