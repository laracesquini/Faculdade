//estruturas e protótipos das funções
typedef struct dados{
    char first_key[6];
    char titulo_portugues[60];
    char titulo_original[59];
    char diretor[30];
    char ano[5];
    char pais[20];
    char nota[2]; 
}Tdados;

typedef struct iprimary{
    char first_key[5];
    int RRN;
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
Iprimario *carrega_indicesP(FILE *fp, Iprimario *vetp);
Isecundario *carrega_indicesS(FILE *fs, Isecundario *vets);
void cria_indices(FILE *fd, FILE *fp, FILE *fs, Iprimario *vetp, Isecundario *vets, int flagp, int flags);
char *cria_chave(Tdados aux);
char *formata_dados(Tdados aux);
Iprimario *alocarP(char *chave, int RRN);
Isecundario *alocarS(char *chave, char *titulo);
int novo_RRN(FILE *fd);
void salvar(FILE *fp, FILE *fs, Iprimario *vetp, Isecundario *vets, int flagp, int flags);
void atualiza_flag(FILE *file, char *nome);
Iprimario *busca(Iprimario *vetp, char *chave);
Iprimario *removerP(Iprimario *h, char *chave);
Isecundario *removerS(Isecundario *h, char *chave);
void remove_arquivo(Iprimario *aux, FILE *fd);
void att_arquivo(FILE *fd, int RRN, char *nota);
void imprime_filme(Iprimario *aux, FILE *fd);
Iprimario *busca_secundario(Iprimario *vetp, Isecundario *vets, char *titulo);
void catalogo(FILE *fd);