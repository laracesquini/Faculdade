#include <stdio.h>

int main()
{
  //Declaração de variáveis
  char resp[3][10], gab[10]={'a', 'b', 'c', 'd', 'd', 'c', 'a', 'b', 'c', 'a'};
  int i, j, k=0, count=0, mat;

  for(i=0; i<3; i++)
    {
       printf("\nAluno %d", i+1);
       printf("\nDigite o número da matrícula: ");
       scanf("%d", &mat);
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
      printf("\nAluno %d", i+1);
      printf("\nMatrícula: %d", mat);
      printf("\nRespostas:\n");
      for(j=0; j<10; j++)
        printf(" %c", resp[i][j]);
      printf("\n%d pontos", count);
      if(count>=7)
        printf("\nAprovado!\n");
      else
        printf("\nReprovado\n");
      count=0;
      mat=0;
    }
    
  return 0;
}