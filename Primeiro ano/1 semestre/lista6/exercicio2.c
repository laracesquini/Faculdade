#include <stdio.h>

int main()
{
  //Declaração de variáveis
  int A[5][5], i, j;

  //Programa principal
  for(i=0; i<5; i++)
    for(j=0; j<5; j++)
      {
        if(j==i)
          A[i][j]=1;
        else
          A[i][j]=0;
      }
   for(i=0; i<5; i++)
     {
    for(j=0; j<5; j++)
      {
        printf(" %d", A[i][j]);
      }
       printf("\n");
       }
  return 0;
}