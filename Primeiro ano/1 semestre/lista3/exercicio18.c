#include <stdio.h>

int main()
{
  int codigo;

  printf("Digite o código do seu produto: ");
  scanf("%d", &codigo);
  switch(codigo)
  {
    case 1: printf("\nAlimento não perecível."); break;
    case 2 ... 4: printf("\nAlimento perecível."); break;
    case 5:
    case 6: printf("\nVestuário."); break;
    case 7: printf("\nHigiene pessoal"); break;
    case 8 ... 13: printf("\nLimpeza e Utensílios domésticos"); break;
    default: printf("Inválido");
    }

  return 0;
}