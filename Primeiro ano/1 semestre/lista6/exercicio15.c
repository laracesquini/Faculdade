#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
  int B[5][10], i, j, soma1=0, soma2=0;

  srand(time(NULL));

  for(i=0; i<5; i++)
    {
      for(j=0; j<10; j++)
        {
          B[i][j]=1+rand()%10;
          printf(" %d", B[i][j]);
          
        }
      printf("\n");
    }

  
  for(i=0; i<5; i++)
    {
      
      soma1=soma1+B[i][4];
    }

  
  for(j=0; j<10; j++)
    {
      soma2=soma2+B[3][j];
    }

  printf("A soma da quarta coluna é %d", soma1);
  printf("\nA soma da tercira linha é %d", soma2);
  

  return 0;
}