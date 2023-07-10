#include <stdio.h>

int main()
{
  //Declaração de variáveis
  int A[4][4], i, j;

  //Programa principal
  for(i=0; i<4; i++)
    for(j=0; j<4; j++)
      {
        A[i][j]=i*j;
      }
   for(i=0; i<4; i++)
     {
    for(j=0; j<4; j++)
      {
        printf(" %d", A[i][j]);
      }
       printf("\n");
       }
  return 0;
}