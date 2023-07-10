#include <stdio.h>

int main()
{
  struct produto {
    char nome[20];
    char descricao[20];
    int codigo;
    float preco;
    int baixa[6];
  } prod[20];

  int i,j;
  
  for(j=0; j<20; j++)
  {
    printf("\nDigite o nome do produto: ");
    scanf(" %[^\n]s", prod[j].nome);
    printf("\nDigite a descrição do produto: ");
    scanf(" %[^\n]s", prod[j].descricao);
    printf("\nDigite o código do produto: ");
    scanf("%d", &prod[j].codigo);
    printf("\nDigite o preço do produto: ");
    scanf("%f", &prod[j].preco);

    for(i=0; i<6; i++)
    {
      printf("\nDigite a baixa do dia %d: ", i+1);
      scanf("%d", &prod[j].baixa[i]);
    }

    printf("\nProduto %d", j+1);
    printf("\nNome: %s", prod[j].nome);
    printf("\nDescrição: %s", prod[j].descricao);
    printf("\nCódigo: %d", prod[j].codigo);
    printf("\nPreço: %.2f", prod[j].preco);
    printf("\nAs baixas da semana são: ");
    for(i=0; i<6; i++)
    {
      printf("\nDia %d: %d", i+1, prod[j].baixa[i]);
    }
  }
  return 0;
}
