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
void escreve_no(int RRN, node *no, FILE *fp);
node *le_no(int RRN, FILE *fp);
node *cria_no();
int novo_RRN_no(FILE *fp);
int insere_folha(node *folha, char *chave, int RRN);
node *busca_no(node *raiz, char *chave, FILE *fp);
int inserir(char *chave, int RRN_dado, node **raiz, FILE *fp);
void insere_pai(node *no_antigo, char *chave_promovida, node *novo_no, node **raiz, FILE *fp);
int busca(node *raiz, char *chave, FILE *fp);
Isecundario *insereS(Isecundario *h, Isecundario *p);
Isecundario *carrega_indicesS(FILE *fs, Isecundario *vets);
void cria_indices(FILE *fd, FILE *fs, Isecundario *vets, int flags);
char *cria_chave(Tdados aux);
char *formata_dados(Tdados aux);
Isecundario *alocarS(char *chave, char *titulo);
int novo_RRN(FILE *fd);
void salvar(FILE *fs, Isecundario *vets, int flags);
void atualiza_flag(FILE *file, char *nome);
void att_arquivo(FILE *fd, int RRN, char *nota);
void att_raiz(int RRN, FILE *fp);
void imprime_filme(int RRN, FILE *fd);
void busca_secundario(node *raiz, Isecundario *vets , char *titulo, FILE *fd, FILE *fp);
void catalogo(FILE *fd, FILE *fp);
