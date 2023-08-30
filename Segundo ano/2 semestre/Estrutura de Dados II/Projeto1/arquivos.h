//estruturas e protótipos das funções
typedef struct dados{
    char first_key[5];
    char titulo_portugues[62];
    char titulo_original[63];
    char diretor[30];
    char ano[4];
    char pais[20];
    char nota[1]; 
}Tdados;

typedef struct iprimary{
    char first_key[5];
    int RNN;
    struct iprimary *prox;
}Iprimario;

typedef struct ititle{
    char titulo[62];
    char first_key[5];
    struct ititle *prox;
}Isecundario;

int file_exists(char *nome);
Iprimario *insereP(Iprimario *h, Iprimario *p);
Isecundario *insereS(Isecundario *h, Isecundario *p);