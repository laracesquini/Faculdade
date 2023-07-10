#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define n 15

int main()
{
  //Declaração de variáveis
  int v[n], i, j, aux, k, l, op;

  srand(time(NULL));

  for(i=0; i<n; i++)
    {
      v[i]=1+rand()%100;
    }
    
  do{
    do{
      printf("\n\t----OPERAÇÕES NO VETOR----");
      printf("\n\t[1]Apresentar elementos em ordem crescente");
      printf("\n\t[2]Apresentar elementos em ordem decrescente");
      printf("\n\t[3]Imprimir todo o vetor");
      printf("\n\t[4]Imprimir as posições de um intervalo específico");
      printf("\n\t[5]Encerrar");
      printf("\n\tEscolha uma opção: ");
      scanf("%d", &op);
      if(op<1 || op>5)
      printf("\n\tOpção inválida");
  } while(op<1 || op>5); 

  if(op==1)
  {
    printf("\n\tOrdem crescente:");
    for(i=0; i<n; i++)
      {
      for(j=i+1; j<n; j++)
        {
          if(v[j]<v[i])
          {
            aux=v[i];
            v[i]=v[j];
            v[j]=aux;
          }
        }
        printf(" %d", v[i]);
      }
    printf("\n");
  }
  else if(op==2)
  {
    printf("\n\tOrdem decrescente:");
    for(i=0; i<n; i++)
      {
      for(j=i+1; j<n; j++)
        {
          if(v[j]>v[i])
          {
            aux=v[i];
            v[i]=v[j];
            v[j]=aux;
          }
        }
        printf(" %d", v[i]);
        }
    printf("\n");
   }
  else if(op==3)
  {
    printf("\n\tVetor: ");
    for(i=0; i<n; i++)
     printf(" %d", v[i]);
    printf("\n");
    }
  else if(op==4)
  {
    printf("Digite o intervalo que você gostaria de ver: ");
    scanf("%d e %d", &k, &l);
    i=k-1;
    j=l-1;
    for(i=k-1; i<=j; i++)
      printf(" %d", v[i]);
  }
 else if(op==5)
    printf("\n\tPrograma encerrado");
  } while(op!=5);

  return 0;
}