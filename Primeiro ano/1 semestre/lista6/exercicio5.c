#include <stdio.h>

int main()
{
  //Declaração de variáveis
  int A[5][5], i, j, X;

  //Programa principal
  printf("Digite um valor: ");
  scanf("%d", &X);
  
  for(i=0; i<5; i++)
    for(j=0; j<5; j++)
      {
        printf("\nDigite um valor para a matriz: ");
        scanf("%d", &A[i][j]);
        
      }

   for(i=0; i<5; i++)
     {
    for(j=0; j<5; j++)
      {
       printf(" %d", A[i][j]);
      }
      printf("\n");  
      }

        
  for(i=0; i<5; i++)
    for(j=0; j<5; j++)
      {
       if(A[i][j]==X)
       printf("Elemento encontrado na linha %d e coluna %d", i, j);
        }
   
  return 0;
}