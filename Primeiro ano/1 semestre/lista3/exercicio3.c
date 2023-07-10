#include <stdio.h>

int main()
{
  char sexo;

  printf("Digite o seu sexo (F ou M): ");
  scanf("%c", &sexo);
  if(sexo=='F' || sexo=='f')
    printf("Sexo válido: feminino");
  else if(sexo=='M' || sexo=='m')
    printf("Sexo válido: masculino");
  else
    printf("Sexo inválido");

  return 0;
}