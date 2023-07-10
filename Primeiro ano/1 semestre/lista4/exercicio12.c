#include <stdio.h>

int main()
{

  //Declaração de variáveis
  char sexo;
  int i, n_m, n_h;
  float altura, maior_m, maior_h, menor_m, menor_h, diferenca, total_h, total_m;

  n_m=0;
  n_h=0;

  //Programa principal
  for(i=0;i<=4; i++) 
  {
    do{
      printf("\nDigite o sexo <M>asculino ou <F>eminino: \n");
      scanf(" %c", &sexo);
    } while(sexo!='m' && sexo!='f');
  
    printf("\nDigite a altura: ");
    scanf("%f", &altura);

    if(sexo=='m') 
    {
        if(n_h==0) 
        {
            maior_h=altura;
            menor_h=altura;
            total_h=altura;
        }
        else 
        {
            if(altura>maior_h) 
            {
                maior_h=altura;
            }
            else if(altura<menor_h) 
            {
                menor_h=altura;
            }
            total_h=total_h+altura;
        }
        n_h++;
    }
    else 
    {
        if(n_m==0) 
        {
            maior_m=altura;
            menor_m=altura;
            total_m=altura;
        }
        else 
        {
            if(altura>maior_m) 
            {
                maior_m=altura;
            }
            else if(altura<menor_m) 
            {
                menor_m=altura;
            }
            total_m=total_m+altura;
        }
        n_m++;
    }
  }
  //item a
  printf("\nA altura da maior mulher do grupo é %.2f", maior_m);
  printf("\nA altura da menor mulher do grupo é %.2f", menor_m);
  printf("\nA altura do maior homem do grupo é %.2f", maior_h);
  printf("\nA altura do menor homem do grupo é %.2f", menor_h);
  //item b
  printf("\nA altura média das mulheres é %.2f", total_m/n_m);
  printf("\nA altura média dos homens é %.2f", total_h/n_h);
  //item c
  printf("\nO número de homens é %d", n_h);
  
  diferenca=n_h-n_m;

  if(diferenca!=0)
    diferenca=(diferenca/(n_h+n_m))*100;

  printf("\nA diferença é %.2f%%", diferenca);
  
  return 0;
}
  