#include <stdio.h>

int main()
{
  //Declaração de variávies
  int A[5], i, diferenca, maior_dif, ind_primeiro, ind_segundo;

  //Programa principal
  for(i=0; i<5; i++)
    {
      printf("Digite um valor para A[%d]", i);
      scanf("%d", &A[i]);
    }
  for(i=0; i<5; i++)
    {
      diferenca=A[i]-A[i+1];
       if(i==0) 
       {
            maior_dif=diferenca;
            ind_primeiro=i;
            ind_segundo=i+1;
        }
       else
         if(diferenca>maior_dif)
        {
           maior_dif=diferenca;
           ind_primeiro=i;
           ind_segundo=i+1;
        }
      
    }
  printf("A maior diferença é %d", maior_dif);
  printf("\nOs índices são: %d e %d", ind_primeiro, ind_segundo);
  
  return 0;
}
