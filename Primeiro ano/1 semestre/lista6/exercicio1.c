#include <stdio.h>

int main()
{
  //Declaração de variáveis
  int A[4][4], i, j, count=0;

  //Programa principal
  for(i=0; i<4; i++)
    for(j=0; j<4; j++)
      {
        printf("Digite uma valor para a matriz: ");
        scanf("%d", &A[i][j]);
        if(A[i][j]>10)
          count++;
      }

  printf("Nessa matriz existe %d elementos maiores que 10", count);
  return 0;
}