#include <stdio.h>

int main()
{
  //Declaração de variáveis
  int c1=0, c2=0, c3=0, c4=0, nulo=0, brancos=0, op, total;

  //Programa principal
  do{
    printf("\nELEIÇÃO");
    printf("\nCandidato 1: vote 1");
    printf("\nCandidato 2: vote 2");
    printf("\nCandidato 3: vote 3");
    printf("\nCandidato 4: vote 4");
    printf("\nNulo: vote 5");
    printf("\nBranco: vote 6");
    printf("\nPara encerrar o programa, digite 0");
    do{ 
        printf("\nEscolha sua opção: ");
        scanf("%d", &op);
        if(op<0 || op>6)
            printf("\nOpção inválida");
    }while(op<0 || op>6); 

    if(op!=0) {
        printf("\nSeu voto foi computado!");

        switch(op)
        {
            case 1: c1++;break;
            case 2: c2++;break;
            case 3: c3++;break;
            case 4: c4++;break;
            case 5: nulo++;break;
            default: brancos++;break;
        }
    }
        
  } while(op!=0);

  total=c1+c2+c3+c4+nulo+brancos;

  if(c1!=0)
    printf("\nO total de votos do candidato 1 é: %d %.2f%%", c1, ((float)c1/(float)total)*100);
  else
    printf("\nO total de votos do candidato 1 é %d, %d", c1, c1);
  if(c2!=0)
    printf("\nO total de votos do candidato 2 é: %d %.2f%%", c2, ((float)c2/(float)total)*100);
  else
    printf("\nO total de votos do candidato 2 é %d, %d", c2, c2);
  if(c3!=0)
    printf("\nO total de votos do candidato 3 é: %d %.2f%%", c3, ((float)c3/(float)total)*100);
  else
    printf("\nO total de votos do candidato 3 é %d, %d", c3, c3);
  if(c4!=0)
    printf("\nO total de votos do candidato 4 é: %d %.2f%%", c4, ((float)c4/(float)total)*100);
  else
    printf("\nO total de votos do candidato 4 é %d, %d", c4, c4);
    
  printf("\nNúmero total de votos é: %d", total);

  if(nulo!=0)
    printf("\nO total de votos nulos é: %d %.2f%%", nulo, ((float)nulo/(float)total)*100);
  else
    printf("\nO total de votos nulos é %d, %d", nulo, nulo);
  if(brancos!=0)
    printf("\nO total de votos brancos é: %d %.2f%%", brancos, ((float)brancos/(float)total)*100);
  else
    printf("\nO total de votos brancos é %d, %d", brancos, brancos);

  return 0;
}