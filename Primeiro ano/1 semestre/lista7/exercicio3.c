#include <stdio.h>
#define n 10

int main() {

  struct cheque
  {
    char nome[20];
    int dia;
    int mes;
    int ano;
    float valor;
  }cheque1;

  printf("\nDigite seu nome: ");
  scanf("%s", cheque1.nome);
  printf("\nDigite a data(dd/mm/aa): ");
  scanf("%d/%d/%d", &cheque1.dia, &cheque1.mes, &cheque1.ano);
  printf("\nDigite o valor: ");
  scanf("%f", &cheque1.valor);

  printf("\nNome: %s", cheque1.nome);
  printf("\nData: %d/%d/%d", cheque1.dia, cheque1.mes, cheque1.ano);
  printf("\nValor: %.2f", cheque1.valor);

  return 0;
}