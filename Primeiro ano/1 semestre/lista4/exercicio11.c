#include <stdio.h>

int main()
{
  char nome[40], endereço[50], fone[15], cidade[20], estado[20];
  int diarias, i, total_diarias;
  float total_hotel, preço;
  
  total_hotel=0;
  total_diarias=0;
  
  for(i=1; i<=200; i++)
  {
    printf("\n\nREGISTRO - Hóspede %d", i);
    printf("\n\nAdicione seus dados:");
    printf("\nNome completo: ");
    scanf(" %[^\n]s", nome);
    printf("\nEndereço: ");
    scanf(" %[^\n]s", endereço);
    printf("\nTelefone:(DDD) ");
    scanf(" %[^\n]s", fone);
    printf("\nCidade: ");
    scanf(" %[^\n]s", cidade);
    printf("\nEstado: ");
    scanf(" %[^\n]s", estado);
    printf("\nNúmero de diárias: ");
    scanf("%d", &diarias);
    
    if(diarias<15) 
        preço=20+(300*diarias);
    else if(diarias==15)
        preço=14+(300*diarias);
    else
        preço=12+(300*diarias);
    
    printf("\nNome: %s", nome);
    printf("\nEndereço: %s", endereço);
    printf("\nTelefone: %s", fone);
    printf("\nCidade: %s", cidade);
    printf("\nEstado: %s", estado);
    printf("\nNúmero de díarias: %d", diarias);
    printf("\nO total a ser pago é %.2f", preço);

    total_hotel=total_hotel+preço;
    total_diarias=total_diarias+diarias;
    }

  printf("\nO total ganho pelo hotel é %.2f", total_hotel);
  printf("\nO total de diárias é %d", total_diarias);

  return 0;
}