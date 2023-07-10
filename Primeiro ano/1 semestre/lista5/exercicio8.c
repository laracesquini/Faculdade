#include <stdio.h>

int main()
{
  int op, estoque, prod[5]={0, 0, 0, 0, 0}, i, estoque_total, j, k;
  float preco[5]={0, 0, 0, 0, 0};

  do{
   do{
        printf("\n\t\t\t ----Controle de estoque----");
        printf("\n\tEscolha uma opção: \n");
        printf("\t1. Aumentar estoque\n");
        printf("\t2. Baixar estoque\n");
        printf("\t3. Visualizar estoque de um produto\n");
        printf("\t4. Visualizar estoque total\n");
        printf("\t5. Aumentar preço\n");
        printf("\t6. Diminuir preço\n");
        printf("\t7. Trocar produto\n");
        printf("\t8. Sair\n");
        printf("\tEscolha: ");
        scanf("%d", &op);
        if(op<1 || op>8)
        printf("\tOpção inválida");
    }while(op<1 || op>8);

   if(op==1) 
   {
    do{ 
        printf("\t1. Produto 1\n");
        printf("\t2. Produto 2\n");
        printf("\t3. Produto 3\n");
        printf("\t4. Produto 4\n");
        printf("\t5. Produto 5\n");
        printf("\tDigite o produto que você deseja inserir no estoque: \n");
        scanf("%d", &i);
        if(i<1 || i>5)
            printf("\tInválido\n");
    } while(i<1 || i>5);

    if(i==1 || i==2 || i==3 || i==4 || i==5) 
    {
       prod[i-1]++;
       printf("\n\tQuantidade do produto %d em estoque: %d\n", i, prod[i-1]);
    }
    }
    
    else if(op==2)
    {
     do{ 
        printf("\t1. Produto 1\n");
        printf("\t2. Produto 2\n");
        printf("\t3. Produto 3\n");
        printf("\t4. Produto 4\n");
        printf("\t5. Produto 5\n");
        printf("\tDigite o produto que você deseja tirar do estoque: \n");
        scanf("%d", &i);
      if(i<1 || i>5)
        printf("\tInválido\n");
    } while(i<1 || i>5);

     if(i==1 || i==2 || i==3 || i==4 || i==5)
     {
       if(prod[i-1]==0)
         printf("\tEstoque vazio\n");
       else 
       {
         prod[i-1]--;
         printf("\nQuantidade do produro %d em estoque: %d\n", i, prod[i-1]);
       }
      }
    }
    
    else if(op==3)
    {
     do{ 
        printf("\t1. Produto 1\n");
        printf("\t2. Produto 2\n");
        printf("\t3. Produto 3\n");
        printf("\t4. Produto 4\n");
        printf("\t5. Produto 5\n");
        printf("\tDigite o produto que você deseja visualizar o estoque: \n");
        scanf("%d", &i);
        if(i<1 || i>5)
            printf("\tInválido\n");
    } while(i<1 || i>5);

    if(i==1 || i==2 || i==3 || i==4 || i==5)
    {
        if(prod[i-1]==0)
            printf("\tEstoque vazio\n");
        else
            printf("\nQuantidade do produto %d em estoque: %d\n", i, prod[i-1]);
           
    }
   }
   
   else if(op==4)
   {
     estoque_total=prod[0]+prod[1]+prod[2]+prod[3]+prod[4];
     printf("\tO estoque total é: %d\n", estoque_total);
   }
   
   else if(op==5)
   {
     do{ 
        printf("\t1. Produto 1\n");
        printf("\t2. Produto 2\n");
        printf("\t3. Produto 3\n");
        printf("\t4. Produto 4\n");
        printf("\t5. Produto 5\n");
        printf("\tDigite o produto que você deseja aumentar o preço: \n");
        scanf("%d", &j);
        if(j<1 || j>5)
            printf("\tInválido");
    } while(j<1 || j>5);

     if(j==1 || j==2 || j==3 || j==4 || j==5)
     {
       printf("\nQual é o preço que você deseja atribuir para esse produto? ");
       scanf("%f", &preco[j-1]);
       printf("\n\tO preço do produto %d é: %.2f", j, preco[j-1]);
         
     }
   }

   else if(op==6)
   {
      do{ 
        printf("\t1. Produto 1\n");
        printf("\t2. Produto 2\n");
        printf("\t3. Produto 3\n");
        printf("\t4. Produto 4\n");
        printf("\t5. Produto 5\n");
        printf("\tDigite o produto que você deseja diminuir o preço: \n");
        scanf("%d", &j);
        if(j<1 || j>5)
            printf("\tInválido\n");
    } while(j<1 || j>5);

     if(j==1 || j==2 || j==3 || j==4 || j==5)
     {
       if(preco[j-1]==0)
         printf("\tEssa mercadoria não tem preço\n");
       else
       {
        printf("\n\tQual é o preço que você deseja atribuir para esse produto? ");
        scanf("%f", &preco[j-1]);
        printf("\n\tO preço do produto %d é: %.2f", j, preco[j-1]);
       }
     }
    }

   else if(op==7)
   {
     printf("\n\tQuais produtos vc deseja trocar?");
     scanf("%d e %d", &i, &k);
     if(prod[i-1]==0)
       printf("\n\tDesculpa, não temos esse produto\n");
     else
     {  
     prod[i-1]--;
     prod[k-1]++;
    }
    }
} while(op!=8);

return 0;
}
