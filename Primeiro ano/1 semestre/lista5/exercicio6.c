#include <stdio.h>
#include <stdlib.h>

int main()
{
  //Variáveis
  int v[10], op, count=0, primeiro=0, ultimo=0;
  
  do{
    do{
        printf("Escolha uma opção: \n");
        printf("1. Consultar primeiro da fila\n");
        printf("2. Incluir elemento na fila\n");
        printf("3. Atender o primeiro da fila\n");
        printf("4. Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);
        if(op<1 || op>4)
            printf("Opção inválida\n");
    }while(op<1 || op>4);

  if(op==1)
  {
    if(count==0)
      printf("Fila Vazia\n");
    else
      printf("O primeiro elemento é: %d\n", v[primeiro]);
    }
  else if(op==2) 
  {
    if(count==10)
      printf("Fila cheia\n");
    else 
    {
        printf("Digite o elemento que deseja incluir: \n");
        scanf("%d", &v[ultimo]);
        count++;
        ultimo++;
    }
  }
  else if(op==3) 
  {
    if(count==0)
      printf("Fila vazia\n");
    else 
    {
      printf("O primeiro elemento da fila é %d\n", v[primeiro]);
      primeiro++;
      count--;
    }
    }
    }while(op!=4);

  return 0;
}
