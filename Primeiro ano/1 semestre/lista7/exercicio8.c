#include <stdio.h>
#define m 3

int main()
{
//Declaração das variáveis
  
  typedef struct clientes {
    char nome[40];
    char sobrenome [40];
    char sexo;
  }Tcli; 

  typedef struct conta {
    Tcli cliente;
    int n_conta;
    int mes; 
    int dia; 
    int ano;
    float saldo;
    float lim_esp;
  }Tconta;

  Tconta banco[m];

  float saldo_mulheres=0, saldo_homens=0, maior_saldo, menor_saldo, maior_lim;
  int cliente_lim, mulheres=0, homens=0, cliente_antigo, menor_ano, menor_mes, menor_dia, saldo_negativo=0; 

  //Vetor para ordenação dos saldos
  float saldos[m], aux;
  int k, j, i;
  
//Entrada de dados
  for(int i=0; i<m; i++)
    {
      printf("\nCliente %d", i+1);
      printf("\nNome: ");
      scanf(" %[^\n]s", banco[i].cliente.nome);
      printf("\nSobrenome: ");
      scanf(" %[^\n]s", banco[i].cliente.sobrenome);
      do{ 
        printf("\nSexo - [f]eminino ou [m]asculino: ");
        scanf(" %c", &banco[i].cliente.sexo);
          if(banco[i].cliente.sexo != 'f' && banco[i].cliente.sexo != 'F' && banco[i].cliente.sexo != 'm' && banco[i].cliente.sexo != 'M')
            printf("\nInválido");
        } while(banco[i].cliente.sexo != 'f' && banco[i].cliente.sexo != 'F' && banco[i].cliente.sexo != 'm' && banco[i].cliente.sexo != 'M' );
      printf("\nNúmero da conta: ");
      scanf("%d", &banco[i].n_conta);
      printf("\nData de abertura da conta: ");
      do{
        printf("\nDia: ");
        scanf("%d", &banco[i].dia);
          if(banco[i].dia<0 || banco[i].dia>31)
            printf("\nInválido");
        }while(banco[i].dia<0 || banco[i].dia>31);
      do{
        printf("\nMês: ");
        scanf("%d", &banco[i].mes);
          if(banco[i].mes<0 || banco[i].mes>12)
            printf("\nInválido");
        } while(banco[i].mes<0 || banco[i].mes>12);
      do{
        printf("\nAno: ");
        scanf("%d", &banco[i].ano);
          if(banco[i].ano<1950 || banco[i].ano>2022)
            printf("\nInválido");
        } while(banco[i].ano<1950 || banco[i].ano>2022);
      printf("\nSaldo: ");
      scanf("%f", &banco[i].saldo);
      printf("\nLimite especial: ");
      scanf("%f", &banco[i].lim_esp);

      //Cálculo do maior e menor saldo
      if(banco[i].saldo>0)
      {
        if(i==0)
        {
          maior_saldo = banco[i].saldo;
          menor_saldo = banco[i].saldo;
        }
        else
        {
          if(banco[i].saldo > maior_saldo)
            maior_saldo = banco[i].saldo;
          if(banco[i].saldo < menor_saldo)
            menor_saldo = banco[i].saldo;
        }
      }
      else
      {
        saldo_negativo++;
      }

      //Cálculo da média do saldo das mulheres e dos homens
      if(banco[i].cliente.sexo == 'f' || banco[i].cliente.sexo == 'F')
      {
        saldo_mulheres = saldo_mulheres + banco[i].saldo;
        mulheres++;
      }
      else
      {
        saldo_homens = saldo_homens + banco[i].saldo;
        homens++;
      }

      //Cálculo do cliente mais antigo

      if(i==0)
      {
        menor_ano = banco[i].ano;
        menor_mes = banco[i].mes;
        menor_dia = banco[i].dia;
        cliente_antigo = i+1;
      }
      else
      {
        if(banco[i].ano < menor_ano)
        {
          menor_ano = banco[i].ano;
          cliente_antigo = i+1;
        }
        else if(banco[i].ano == menor_ano)
        {
          if(banco[i].mes < menor_mes)
          {
            menor_mes = banco[i].mes;
            cliente_antigo = i+1;
          }
          else if(banco[i].mes == menor_mes)
          {
            if(banco[i].dia < menor_dia)
            {
              menor_dia = banco[i].dia;
              cliente_antigo = i+1;
            }
            else if(banco[i].dia == menor_dia)
            cliente_antigo = i+1;
          }
        }
      }

      //Cálculo do cliente com maior limite especial
      if(i==0)
      {
        maior_lim = banco[i].lim_esp;
        cliente_lim = i+1;
      }
      else
      {
        if(banco[i].lim_esp > maior_lim)
        {
          maior_lim = banco[i].lim_esp;
          cliente_lim = i+1;
        }
      }
    }
//Saída de dados
  printf("\nSaldo médio das mulheres: %.2f", (saldo_mulheres/mulheres));
  printf("\nSaldo médio dos homenes: %.2f" , saldo_homens/homens);
  printf("\nO maior saldo é: %.2f reais", maior_saldo);
  printf("\nO menor saldo é: %.2f reais", menor_saldo);
  printf("\nO cliente mais antigo é: cliente %d. Abriu sua conta em %d/%d/%d", cliente_antigo, menor_dia, menor_mes, menor_ano);
  printf("\nO cliente com maior limite especial é: cliente %d. Seu limite é %.2f reais", cliente_lim, maior_lim);
  //Clientes com saldo negativo
  printf("\nO clientes com saldos negativos são: ");
  if(saldo_negativo != 0)
  {
    for(int i=0; i<m; i++)
      {
        if(banco[i].saldo < 0)
          printf("\nCliente %d", i+1);
      }
  }
  else
    printf("\nNenhum");
  
  //Listar clientes por saldo bancário
  for(int i=0; i<m; i++)
    {
      saldos[k] = banco[i].saldo;
      k++;
    }

  for(int k=0; k<m; k++)
    {
      for(int j=k+1; j<m; j++)
        {
          if(saldos[j]<saldos[k])
          {
            aux = saldos[k];
            saldos[k] = saldos[j];
            saldos[j] = aux;
          }
        }
    }
k=0;
  printf("\nListas dos saldos: ");
  for(int i=0; i<m; i++)
    {
      printf("\n%.2f", saldos[k]);
      k++;
    }
  
  return 0;
}
