#include <stdio.h>
#define n 4

int main() {

  //Declaração de variáveis
  int A[n][n], i, j, maior, linha_maior, coluna_maior;

  //Programa principal
  for(i=0; i<n; i++)
    for(j=0; j<n; j++)
      {
        printf("\nDigite um valor para A[%d][%d]: ", i, j);
        scanf("%d", &A[i][j]);
        if(i==0 && j==0)
        {
          maior=A[i][j];
          linha_maior=i;
          coluna_maior=j;
        }

        else
          if(A[i][j]>maior)
          {
            maior=A[i][j];
            linha_maior=i;
            coluna_maior=j;
        
            }
        }
  
  for(i=0; i<n; i++)
    {
      for(j=0; j<n; j++)
      {
        printf(" %d", A[i][j]);
      }
      printf("\n");
    }

  printf("\nO maior valor é %d", maior);
  printf("\nEstá localinado na linha %d e na coluna %d", linha_maior, coluna_maior);
  
  return 0;
}