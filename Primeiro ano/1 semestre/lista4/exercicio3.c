#include <stdio.h>

int main()
{
  int cod_orig, i;

  for(i=1; i<=10; i++) 
  {
    printf("\n\nAdicione o código de origem do seu produto: ");
    scanf("%d", &cod_orig);
    switch(cod_orig)
    { 
        case 1: printf("\nSeu produto é procedente do Sul"); break;
        case 2: printf("\nSeu produto é procedente do Norte"); break;
        case 3: printf("\nSeu produto é procedente do Leste"); break;
        case 4: printf("\nSeu produto é procedente do Oeste"); break;
        case 5:
        case 12 ... 15:
        case 6: printf("\nSeu produto é procedente Nordeste"); break;
        case 7 ... 9: printf("\nSeu produto é procedente do Sudeste"); break;
        case 10:
        case 11: printf("\nSeu produto é procedente do Centro-Oeste"); break;
        default: printf("\nSeu produto é importado");
    }
}
  return 0;
}