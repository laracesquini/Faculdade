#include <stdio.h>

int main()
{
  //Declaração de variáveis
  char resp[5][10], gab[10]={'a', 'b', 'c', 'd', 'd', 'c', 'a', 'b', 'c', 'a'};
  int i, j, k=0, count=0;

  for(i=0; i<5; i++)
    {
    for(j=0; j<10; j++)
      {
        do{
          printf("\nDigite a resposta para o aluno %d, questão %d: ", i+1, j+1);
          scanf(" %c", &resp[i][j]);
          if(resp[i][j]!='a' && resp[i][j]!='b' && resp[i][j]!='c' && resp[i][j]!='d')
            printf("\nResposta inválida!\n");
          else
          {
            if(resp[i][j]==gab[k])
              count++;
           k++;
          }
        }while(resp[i][j]!='a' && resp[i][j]!='b' && resp[i][j]!='c' && resp[i][j]!='d');
      }
      
  printf("\nAluno %d: %d pontos\n", i+1, count);
      count=0;
    }

    return 0;
}