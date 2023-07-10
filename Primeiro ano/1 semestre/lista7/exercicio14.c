#include <stdio.h>

int main()
{
  //Declaração de variáveis
  typedef struct tempo {
    int hora_ini;
    int hora_fim;
    int min_ini;
    int min_fim;
  }Tempo;
  Tempo T;

  int hora_total, min, seg, min_total;

  do{
    printf("\nDigite a hora que o jogo foi iniciado: ");
    scanf("%d", &T.hora_ini);
  } while(T.hora_ini<0 || T.hora_ini>23);
  do{
    printf("\nDigite o minuto que o jogo foi iniciado: ");
    scanf("%d", &T.min_ini);
  } while(T.min_ini<0 || T.min_ini>59);
  do{
    printf("\nDigite a hora que o jogo foi finalizado: ");
    scanf("%d", &T.hora_fim);
  } while(T.hora_fim<0 || T.hora_fim>23);
  do{
    printf("\nDigite o minuto que o jogo foi finalizado: ");
    scanf("%d", &T.min_fim);
  }while(T.min_fim<0 || T.min_fim>59);

  if(T.min_fim<T.min_ini)
  {
    T.min_fim = T.min_fim + 60;
    T.hora_fim = T.hora_fim - 1;
  }
  if(T.hora_fim<T.hora_ini)
  {
    T.hora_fim = T.hora_fim + 24;
  }

  hora_total = T.hora_fim - T.hora_ini;
  min_total = T.min_fim - T.min_ini;

  printf("\nO total de tempo jogado foi: %d horas e %d minutos.", hora_total, min_total);

  min = (hora_total*60)+min_total;

  printf("\nTempo expresso em minutos: %d", min);

  seg = (min*60);
  
  printf("\nTempo expresso em segundos: %d", seg);

  return 0;
}