#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define n 4

int main() {

  //Declaração de variáveis
  int A[n][n], i, j, maior;

  //Programa principal
  srand(time(NULL));
  
  for(i=0; i<n; i++)
    {
    for(j=0; j<n; j++)
      {
        A[i][j]=1+rand()%20;
        printf(" %d", A[i][j]);
      }
      printf("\n");
      }
  printf("\n");
  
  for(i=0; i<n; i++)
    {
      for(j=0; j<n; j++)
        {
          if(i<j)
            A[i][j]=0;
          printf(" %d", A[i][j]);
        }
      printf("\n");
    }
 
  return 0;
  }