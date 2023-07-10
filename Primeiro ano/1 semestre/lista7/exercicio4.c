#include <stdio.h>
#include <stdlib.h>

int main()
{
  typedef struct data {
    int dia;
    char mes[15];
    int ano;
  }Tdata;

  typedef struct endereco {
    char rua[40];
    int num;
    char bairro[40];
  }Tend;

  typedef struct cadastro {
    char nome[40];
    Tend end;
    Tdata dat;
    char tel[15];
  }Tcad;

  Tcad contatos[10];
  int i;

  for(i=0; i<10; i++)
    {
      printf("\nDigite o seu nome: ");
      scanf(" %[^\n]s", contatos[i].nome);
      printf("\nDigite seu endereço: ");
      printf("\nRua: ");
      scanf(" %[^\n]s", contatos[i].end.rua);
      printf("Bairro: ");
      scanf(" %[^\n]s", contatos[i].end.bairro);
      printf("Número: ");
      scanf("%d", &contatos[i].end.num);
      printf("\nDigite sua data de nascimento: ");
      printf("\nDia: ");
      scanf("%d", &contatos[i].dat.dia);
      printf("Mês: ");
      scanf(" %s", contatos[i].dat.mes);
      printf("Ano: ");
      scanf("%d", &contatos[i].dat.ano);
      printf("\nDigite seu telefone: ");
      scanf(" %s", contatos[i].tel);

      printf("\nCliente %d", i+1);
      printf("\nNome: %s", contatos[i].nome);
      printf("\nEndereço: %s, %d. Bairro %s", contatos[i].end.rua, contatos[i].end.num, contatos[i].end.bairro);
      printf("\nData de nascimento: %d de %s de %d", contatos[i].dat.dia, contatos[i].dat.mes, contatos[i].dat.ano);
      printf("\nTelefone: %s\n", contatos[i].tel);
    }

  return 0;
  
}