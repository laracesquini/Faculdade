#define ordem 6
//declaração das estruturas utilizadas
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

typedef struct no{
    int RRN;
    int folha; //0 não é, 1 é
    char chaves[ordem][6]; 
    int dadosRRN[ordem]; //só usado se for folha
    int filhos[ordem + 1]; //usado se não for folha
    int numeroChaves;
    int pai;
    int prox; //so nó folha
}node;

//declaração dos protótipos das funções utilizadas
int file_exists(char *nome);
Iprimario *insereP(Iprimario *h, Iprimario *p);
void  insere_folha(node *folha, char *chave, int RRN);
void escreve_no(int RRN, node *no, FILE *fp);
node *le_no(int RRN, FILE *fp);
void inicializa_no(node *no);


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
void busca_secundario(Iprimario *vetp, Isecundario *vets, char *titulo, FILE *fd);
void catalogo(FILE *fd);
void compactar(FILE *fd);