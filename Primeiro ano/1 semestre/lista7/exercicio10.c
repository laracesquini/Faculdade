#include <stdio.h>
#define n 20

int main()
{
  typedef struct cadastro {
    int codigo;
    char email[30];
    int horas;
    char pag;
  }Tcad;

  Tcad clientes[n];
  int i;
  float pagar, total;

  for(i=0; i<n; i++)
    {
      printf("\nDigite o código do cliente: ");
      scanf("%d", &clientes[i].codigo);
      printf("\nDigite o email do cliente: ");
      scanf(" %[^\n]s", clientes[i].email);
      printf("\nDigite o número de horas de acesso do cliente: ");
      scanf("%d", &clientes[i].horas);
      printf("\nO cliente sem páginas? Responda com s(sim) ou n(não): ");
      scanf(" %c", &clientes[i].pag);

      if(clientes[i].horas<=20)
        pagar = 35;
      else
        pagar = 35+((clientes[i].horas-20)*2.5);

      if(clientes[i].pag == 's' || clientes[i].pag == 'S')
        pagar = pagar + 40;

      printf("\nCliente %d", i+1);
      printf("\nCódigo: %d", clientes[i].codigo);
      printf("\nEmail: %s", clientes[i].email);
      printf("\nTotal de horas: %d", clientes[i].horas);
      printf("\nPossui páginas? %c", clientes[i].pag);
      printf("\nTotal a pagar: %.2f reais\n", pagar);

      total = total+pagar;
      pagar = 0;
    }
  printf("\nTotal a receber: %.2f reais", total);

  return 0;
}