#include <stdio.h>

int main()
{
  struct produto {
    char nome[20];
    char descricao[20];
    int codigo;
    float preco;
    int baixa[6];
  } prod;

  int i;

  printf("\nDigite o nome do produto: ");
  scanf(" %[^\n]s", prod.nome);
  printf("\nDigite a descrição do produto: ");
  scanf(" %[^\n]s", prod.descricao);
  printf("\nDigite o código do produto: ");
  scanf("%d", &prod.codigo);
  printf("\nDigite o preço do produto: ");
  scanf("%f", &prod.preco);

  for(i=0; i<6; i++)
    {
      printf("\nDigite a baixa do dia %d: ", i+1);
      scanf("%d", &prod.baixa[i]);
    }

  printf("\nProduto 1");
  printf("\nNome: %s", prod.nome);
  printf("\nDescrição: %s", prod.descricao);
  printf("\nCódigo: %d", prod.codigo);
  printf("\nPreço: %.2f", prod.preco);
  printf("\nAs baixas da semana são: ");
  for(i=0; i<6; i++)
    {
      printf("\nDia %d: %d\n", i+1, prod.baixa[i]);
    }

  return 0;
}