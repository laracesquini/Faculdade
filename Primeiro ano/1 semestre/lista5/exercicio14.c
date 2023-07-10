#include <stdio.h>

int main()
{
  //Declaração de variávies
  int A[5], i, maior;
  
  //Programa principal
  for(i=0; i<5; i++)
    {
      printf("Digite um valor para A[%d]: ", i);
      scanf("%d", &A[i]);
      if(i==0)
        maior=A[i];
      else
        if(A[i]>maior)
          maior=A[i];
    }
  printf("Vetor antes: ");
      
  for(i=0; i<5; i++)
    {
      printf(" %d", A[i]);
    }
  for(i=0; i<5; i++)
    A[i]=A[i]/maior;
  printf("\nVetor depois: ");

  for(i=0; i<5; i++)
    printf(" %d", A[i]);
  
  return 0;
}
