#include <stdio.h>

int main()
{
  int pilha[10], i=0, op;

  
   do{
    do{
      printf("\n\t1.Adicionar elemento");
      printf("\n\t2.Tirar elemento");
      printf("\n\t3.Visualizar pilha");
      printf("\n\t4.Sair");
      printf("\n\tEscolha uma opção: ");
      scanf("%d", &op);
      if(op<1 || op>4)
        printf("\n\tOpção inválida\n");
     } while(op<1 || op>4);

   if(op==1)
   {
     if(i<10) 
     {
       printf("\n\tAdicione um elemento: ");
       scanf("\n\t%d", &pilha[i]);
       i++;
     }
     else
       printf("\n\tPilha cheia!");
  }
   else if(op==2)
  {
    if(i>0)
      i--;
    else
      printf("\n\tNão tem elementos na pilha");
  }
     else if(op==3)
     {
       if(i>0)
        printf("\n\tElemento na pilha: %d", pilha[i-1]);
       else
         printf("\n\tPilha vazia");
       }
       
    }while(op!=4);

  return 0;
    
}