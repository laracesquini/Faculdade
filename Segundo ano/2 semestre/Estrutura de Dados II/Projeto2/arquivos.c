//bibliotecas utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arquivos.h"

//função que verifica se um arquivo existe, retorna 1 se ele existe e 0 se não existe
int file_exists(char *nome)
{
    FILE *fp;

    if(fp = fopen(nome, "r"))
    {
        fclose(fp);
        return 1;
    }

    return 0;
}

//função que insere de forma ordenada o índice primário na lista de índices primários, retornando a nova cabeça da lista
Iprimario *insereP(Iprimario *h, Iprimario *p)
{
    Iprimario *aux, *antes;

    //se a cabeça for nula, retorna o próprio elemento, que será a nova cabeça
    if(!h)
    {
        return p;
    }
    aux = antes = h; //senão, as variáveis auxiliares apontam para a cabeça para começar a busca pelo lugar que o elemento será inserido
    while(aux->prox && strcmp(p->first_key, aux->first_key)>0) //se não chegou no final da lista e o código que será inserido é maior que o atual, continua procurando
    {
        antes = aux;
        aux = aux->prox;
    }
    if(aux == h) //insere antes ou depois da cabeça
    {
        //insere antes da cabeça
        if(strcmp(p->first_key, h->first_key)<0)
        {
            p->prox = h;
            return p;
        }
        //insere depois da cabeça
        else if(strcmp(p->first_key, h->first_key)>0)
        {
            p->prox = h->prox;
            h->prox = p;
            return h;
        }
        else
        return h;
    }
    if(strcmp(p->first_key, aux->first_key)<0) //insere no meio da lista
    {
        antes->prox = p;
        p->prox = aux;
        return h;
    }
    else if(strcmp(p->first_key, aux->first_key)>0) //insere como ultimo elemento
    {
        p->prox = aux->prox;
        aux->prox = p;
        return h;
    }
    else
    return h;
}

//função que insere de forma ordenada o índice secundário na lista de índices secundários, retornando a nova cabeça da lista
Isecundario *insereS(Isecundario *h, Isecundario *p)
{
    Isecundario *aux, *antes;

    //se a cabeça for nula, retorna o próprio elemento, que será a nova cabeça  
    if(!h)
    {
        return p;
    }
    aux = antes = h; //senão, as variáveis auxiliares apontam para a cabeça para começar a busca pelo lugar que o elemento será inserido
    while(aux->prox && strcmp(p->titulo, aux->titulo)>0) //se não chegou no final da lista e o código que será inserido é maior que o atual, continua procurando
    {
        antes = aux;
        aux = aux->prox;
    }
    if(aux == h) //insere antes ou depois da cabeça
    {
        //insere antes da cabeça
        if(strcmp(p->titulo, h->titulo)<0)
        {
            p->prox = h;
            return p;
        }
        //insere depois da cabeça
        else if(strcmp(p->titulo, h->titulo)>=0)
        {
            p->prox = h->prox;
            h->prox = p;
            return h;
        }
    }
    if(strcmp(p->titulo, aux->titulo)<=0) //insere no meio da lista
    {
        antes->prox = p;
        p->prox = aux;
        return h;
    }
    else if(strcmp(p->titulo, aux->titulo)>0) //insere como ultimo elemento
    {
        p->prox = aux->prox;
        aux->prox = p;
        return h;
    }
}

//função que percorre o arquivo de índices primários e carrega eles para a memória RAM, retorna a cabeça da lista
Iprimario *carrega_indicesP(FILE *fp, Iprimario *vetp)
{
    char *token, aux[20];
    int flag;
    Iprimario *auxp;

    //abre o arquivo para leitura e lê a flag
    fp = fopen("iprimary.idx", "r");
    fscanf(fp, "%d", &flag);
    
    //lê cada índice separando o RRN e o código e inserindo na lista que está na memória RAM
    while(fscanf(fp, "%[^#]s", aux) > 0)
    {
        fgetc(fp);
        token = strtok(aux, "@");
        auxp = malloc(sizeof(Iprimario));
        strcpy(auxp->first_key, token);
        token = strtok(NULL, "@");
        auxp->RRN = atoi(token);
        auxp->prox = NULL;
        vetp = insereP(vetp, auxp);
    }

    fclose(fp);
    
    return vetp;
}

//função que percorre o arquivo de índices secundários e carrega eles para a memória RAM, retorna a cabeça da lista
Isecundario *carrega_indicesS(FILE *fs, Isecundario *vets)
{
    char *token, aux[100];
    int flag;
    Isecundario *auxs;

    fs = fopen("ititle.idx", "r");
    fscanf(fs, "%d", &flag);
    
    //lê cada índice separando o título e o código e inserindo na lista que está na memória RAM
    while(fscanf(fs, "%[^#]s", aux) > 0)
    {
        fgetc(fs);
        token = strtok(aux, "@");
        auxs = malloc(sizeof(Isecundario));
        strcpy(auxs->titulo, token);
        token = strtok(NULL, "@");
        strcpy(auxs->first_key, token);
        auxs->prox = NULL;
        vets = insereS(vets, auxs);
    }
    
    fclose(fs);
    
    return vets;
}

//função que cria ou atualiza os índices com base no arquivo de dados
void cria_indices(FILE *fd, FILE *fp, FILE *fs, Iprimario *vetp, Isecundario *vets, int flagp, int flags)
{
    char aux[193], *token;
    Iprimario *auxp;
    Isecundario *auxs;
    int count = 0;

    fd = fopen("movies.dat", "r");

    while(fread(aux, 192, 1, fd) == 1)
    {
        //se o registro começar com o caractere "*", aquele filme foi removido, então não será carregado para os índices
        if(aux[0] == '*')
        {
            count++;
            continue;
        }

        //no caso de estar atualizando os índices, verifica a flag para ver qual índice será atualizado
        token = strtok(aux, "@");
        if(flagp == 0)
        {
            //inicializa as informações do índice primário e adiciona na lista
            auxp = malloc(sizeof(Iprimario));
            strcpy(auxp->first_key, token);
            auxp->RRN = count;
            auxp->prox = NULL;
            count++;

            vetp = insereP(vetp, auxp);
        }
        if(flags == 0)
        {
            //inicializa as informações do índice secundário e adiciona na lista
            auxs = malloc(sizeof(Isecundario));
            strcpy(auxs->first_key, token);
            token = strtok(NULL, "@");
            strcpy(auxs->titulo, token);
            auxs->prox = NULL;

            vets = insereS(vets, auxs);
        }
    }

    fclose(fd);
    //chama a função para escrever os índices atualizados no arquivo
    salvar(fp, fs, vetp, vets, flagp, flags);
    
    return;
}

//função que cria a chave no formato pedido, retorna a chave
char *cria_chave(Tdados aux)
{
    int i;
    char *aux1 = (char *)malloc(4);
    char *aux2 = (char *)malloc(3);
    char upper[30];
    
    //pega a três primeiras letras do sobrenome do diretor
    strncpy(aux1, aux.diretor + 0, 3);
    
    //pega os dois últimos números no ano de lançamento
    strncpy(aux2, aux.ano + 2, 2);

    //concatena as duas strings
    strcat(aux1, aux2);
    aux1[5] = '\0';

    //transforma as letras em maiúsculas
    for (int i = 0; i < strlen(aux1); i++) 
    {
        aux1[i] = toupper(aux1[i]); 
    }
    //retorna o código pronto
    return aux1;
}

//função que formata os dados que foram inseridos pelos usuários, retorna os dados formatados
char *formata_dados(Tdados aux)
{
    char *dados = (char *)malloc(193);
    int i;
    
    //coloca as informações separadas por "@"
    strcpy(dados, aux.first_key);
    strcat(dados, "@");
    strcat(dados, aux.titulo_portugues);
    strcat(dados, "@");
    strcat(dados, aux.titulo_original);
    strcat(dados, "@");
    strcat(dados, aux.diretor);
    strcat(dados, "@");
    strcat(dados, aux.ano);
    strcat(dados, "@");
    strcat(dados, aux.pais);
    strcat(dados, "@");
    strcat(dados, aux.nota);
    strcat(dados, "@");

    int len = strlen(dados);

    //preenche o resto com "#"
    for(i = len; i < 192; i++)
    {
        dados[i] = '#';
    }

    dados[192] = '\0';

    return dados;
}

//função que aloca memória para um elemento do tipo Iprimário, retorna o elemento
Iprimario *alocarP(char *chave, int RRN)
{
    Iprimario *aux;

    aux = malloc(sizeof(Iprimario));
    strcpy(aux->first_key, chave);
    aux->RRN = RRN;
    aux->prox = NULL;

    return aux;
}

//função que aloca memória para um elemento do tipo Isecundário, retorna o elemento
Isecundario *alocarS(char *chave, char *titulo)
{
    Isecundario *aux;

    aux = malloc(sizeof(Isecundario));
    strcpy(aux->first_key, chave);
    strcpy(aux->titulo, titulo);
    aux->prox = NULL;

    return aux;
}

//função que calcula o RRN do filme que será inserido a seguir, retorna o RRN
int novo_RRN(FILE *fd)
{
    int novo;

    fd = fopen("movies.dat", "r");

    fseek(fd, 0, SEEK_END);

    novo = ftell(fd);

    fclose(fd);
    
    novo = (novo/192) - 1;

    return novo;
}

//função que salva os índices no arquivo
void salvar(FILE *fp, FILE *fs, Iprimario *vetp, Isecundario *vets, int flagp, int flags)
{
    Iprimario *auxp;
    Isecundario *auxs;

    if(flagp == 0)
    {
        fp = fopen("iprimary.idx", "w");

        //printa a flag no arquivo
        fprintf(fp, "%d", 1);

        auxp = vetp;
        //printa os dados
        while(auxp != NULL)
        {
            fprintf(fp, "%s@%d@#", auxp->first_key, auxp->RRN);
            auxp = auxp->prox;
        }

        fclose(fp);
    }

    if(flags == 0)
    {
        fs = fopen("ititle.idx", "w");

        //printa a flag no arquivo
        fprintf(fs, "%d", 1);

        auxs = vets;
        //printa os dados
        while(auxs != NULL)
        {
            fprintf(fs, "%s@%s@#", auxs->titulo, auxs->first_key);
            auxs = auxs->prox;
        }

        fclose(fs);
    }
    
    return;
}

//função que atualiza a flag no arquivo de índices
void atualiza_flag(FILE *file, char *nome)
{
    char c;

    file = fopen(nome, "r+");
    c = fgetc(file);
    fseek(file, 0, SEEK_SET);
    fputc('0', file);

    fclose(file);

    return;
}

//função que remove o índice primário da lista de índices primários, retorna a cabeça da lista
Iprimario *removerP(Iprimario *h, char *chave)
{
    Iprimario *aux, *antes;

    aux = h;

    if(aux != NULL && strcmp(aux->first_key, chave) == 0)
    {
        h = aux->prox;
        free(aux);
        return h;
    }

    while(aux != NULL && strcmp(aux->first_key, chave) != 0)
    {
        antes = aux;
        aux = aux->prox;
    }
    if(aux == NULL)
    return aux;

    antes->prox = aux->prox;
    free(aux);

    return h;
}

//função que remove o índice secundário da lista de índices secundários, retorna a cabeça da lista
Isecundario *removerS(Isecundario *h, char *chave)
{
    Isecundario *aux, *antes;

    aux = h;

    if(aux != NULL && strcmp(aux->first_key, chave) == 0)
    {
        h = aux->prox;
        free(aux);
        return h;
    }

    while(aux != NULL && strcmp(aux->first_key, chave) != 0)
    {
        antes = aux;
        aux = aux->prox;
    }
    if(aux == NULL)
    return aux;

    antes->prox = aux->prox;
    free(aux);

    return h;
}

//função que busca um índice primário pela chave, retorna o elemento encontrado ou NULL
Iprimario *busca(Iprimario *vetp, char *chave)
{
    Iprimario *aux;

    aux = vetp;

    while(aux != NULL && strcmp(aux->first_key, chave) != 0)
    {
        aux = aux->prox;
    }

    return aux;
}

//função que remove o filme do arquivo de filmes
void remove_arquivo(Iprimario *aux, FILE *fd)
{
    int byte_offset = 192*aux->RRN;
    
    fd = fopen("movies.dat", "r+");

    fseek(fd, byte_offset, SEEK_SET);
    fprintf(fd, "*|");

    fclose(fd);

    return;
}

//função que atualiza a nota no arquivo de dados
void att_arquivo(FILE *fd, int RRN, char *nota)
{
    int byte_offset = 192*RRN, count;
    char c;

    count = 0;
    fd = fopen("movies.dat", "r+");
    
    fseek(fd, byte_offset, SEEK_SET);
    while(count < 7)
    {
        c = fgetc(fd);
        if(c == '@')
        count++;
    }

    fseek(fd, -2, SEEK_CUR);
    fprintf(fd, "%s", nota);

    fclose(fd);

    return;
}

//função que imprime o filme buscado pelo usuário
void imprime_filme(Iprimario *aux, FILE *fd)
{
    int byte_offset = 192*aux->RRN;
    char filme[193], *token;
    char campos[7][50] = {"Chave: ", "Nome em português: ", "Nome original: ", "Diretor: ", "Ano de lançamento: ", "País: ", "Nota: "};
    
    fd = fopen("movies.dat", "r");

    fseek(fd, byte_offset, SEEK_SET);
    fscanf(fd, " %[^#]s", filme);
    token = strtok(filme, "@");

    printf("\n");
    int i = 0;
    while(token != NULL && i < 7)
    {
        printf(campos[i]);
        printf("%s\n", token);
        token = strtok(NULL, "@");
        i++;
    }
    
    fclose(fd);

    return;
}

//função que busca o filme pelo título e printa os filmes encontrados
void busca_secundario(Iprimario *vetp, Isecundario *vets, char *titulo, FILE *fd)
{
    Isecundario *auxs;
    Iprimario *auxp;
    int stt = 0;

    auxs = vets;
    while(auxs != NULL)
    {
        if(strcmp(auxs->titulo, titulo) == 0)
        {
            stt = 1;
            auxp = vetp;
            while(auxp != NULL && strcmp(auxp->first_key, auxs->first_key) != 0)
            {
                auxp = auxp->prox;
            }
            imprime_filme(auxp, fd);
            auxs = auxs->prox;
        }
        else
        auxs = auxs->prox;
    }

    if(stt == 0)
    printf("Filme não encontrado!\n");
}

//função que printa o catálogo 
void catalogo(FILE *fd)
{
    char filme[193], *token;
    char campos[7][50] = {"Chave: ", "Nome em português: ", "Nome original: ", "Diretor: ", "Ano de lançamento: ", "País: ", "Nota: "};
    int j =1;
    
    fd = fopen("movies.dat", "r");

    while(fread(filme, 192, 1, fd) == 1)
    {
        if(filme[0] == '*')
        continue;
        else
        {
            token = strtok(filme, "@");

            int i = 0;
            printf("\nFilme %d: \n", j);
            while(token != NULL && i < 7)
            {
                printf(campos[i]);
                printf("%s\n", token);
                token = strtok(NULL, "@");
                i++;
            }
            j++;
        }
    }
    printf("\n");
    
    fclose(fd);

    return;
}

//função para compactar o arquivo de dados
void compactar(FILE *fd)
{
    FILE *aux;
    char linha[193];

    fd = fopen("movies.dat", "r");
    aux = fopen("aux.dat", "w");

    while(fread(linha, 192, 1, fd) == 1)
    {
        if(linha[0] == '*')
        continue;
        else
        fwrite(linha, 192, 1, aux);
    }

    fclose(fd);
    fclose(aux);

    fd = fopen("movies.dat", "w");
    aux = fopen("aux.dat", "r");

    while(fread(linha, 192, 1, aux) == 1)
    {
        fwrite(linha, 192, 1, fd);
    }
    fclose(fd);
    fclose(aux);

    remove("aux.dat");
    free(aux);
    
    return;
}

void escreve_no(int RRN, node *no, FILE *fp)
{
    int byte_offset = 65*RRN;
    
    fp = fopen("ibtree.idx", "r+");
    fseek(fp, byte_offset, SEEK_SET);
    //FORMATAR NÓS
    //APARENTEMENTE FUNCIONANDO
    fprintf(fp, "%d|%d|%d|%d|%d|", no->RRN, no->folha, no->numeroChaves, no->pai, no->prox);

    for(int i = 0; i < ordem - 1; i++)
    {
        fprintf(fp, "%s,", no->chaves[i]);
    }
    fputc('|', fp);
    for(int i = 0; i < ordem - 1 ; i++)
    {
        fprintf(fp, "%d,", no->dadosRRN[i]);
    }
    fputc('|', fp);
    for(int i = 0; i < ordem; i++)
    {
        fprintf(fp, "%d,", no->filhos[i]);
    }
    fputc('@', fp);
    fclose(fp);
}

node *le_no(int RRN, FILE *fp)
{
    node *no_lido;
    int byte_offset = 65*RRN;
    char linha[100], *aux1, *aux2, *aux3, *aux4, *aux5, *aux6;

    fp = fopen("ibtree.idx", "r");
    fseek(fp, byte_offset, SEEK_SET);
    //fread(linha, 81, 1, fp);
    //printf("%s \n", linha);
    fscanf(fp, "%[^@]s", linha);
    no_lido = cria_no();

    no_lido->RRN = strtol(strtok(linha, "|"), &aux2, 10);
    no_lido->folha = strtol(strtok(NULL, "|"), &aux2, 10);
    no_lido->numeroChaves = strtol(strtok(NULL, "|"), &aux2, 10);
    no_lido->pai = strtol(strtok(NULL, "|"), &aux2, 10);
    no_lido->prox = strtol(strtok(NULL, "|"), &aux2, 10);

    aux1 = strtok(NULL, "|");
    aux2 = strtok(NULL, "|");
    aux3 = strtok(NULL, "|");

    aux4 = strtok(aux1, ",");
    strcpy(no_lido->chaves[0], aux4);
    for(int i = 1; i<no_lido->numeroChaves; i++)
    {
        aux4 = strtok(NULL, ",");
        strcpy(no_lido->chaves[i], aux4);
    }
    
    aux4 = strtok(aux2, ",");
    no_lido->dadosRRN[0] = strtol(aux4, &aux5, 10);
    for(int i = 1; i<no_lido->numeroChaves; i++)
    {
        aux4 = strtok(NULL, ",");
        no_lido->dadosRRN[i] = strtol(aux4, &aux5, 10);
    }

    aux4 = strtok(aux3, ",");
    no_lido->filhos[0] = strtol(aux4, &aux5, 10);
    for(int i = 1; i<(no_lido->numeroChaves + 1); i++)
    {
        aux4 = strtok(NULL, ",");
        no_lido->filhos[i] = strtol(aux4, &aux5, 10);;
    } 
    fclose(fp);

    return no_lido;
}

node *cria_no()
{
    node *no;
    no = malloc(sizeof(node));

    no->RRN = no->pai = no->prox = no->folha = 0;
    no->numeroChaves = 0;
    for(int i = 0; i < ordem - 1; i++)
    {
        no->dadosRRN[i] = 0;
        strcpy(no->chaves[i], "#####");
    }
    for(int i = 0; i < ordem; i++)
    {
        no->filhos[i] = 0;
    }

    return no;
}

int novo_RRN_no(FILE *fp)
{
    int novo;

    fp = fopen("ibtree.idx", "r");

    fseek(fp, 0, SEEK_END);

    novo = ftell(fp);

    fclose(fp);
    
    novo = (novo/65);

    return novo;
}

void  insere_folha(node *folha, char *chave, int RRN)
{
    if(folha->numeroChaves != 0)
    {
        char temp1[ordem][6]; 
        int RRNs[ordem], tam; 

        for(int i = 0; i < folha->numeroChaves; i++)
        {
            strcpy(temp1[i], folha->chaves[i]);
            RRNs[i] = folha->dadosRRN[i];
        }

        tam = folha->numeroChaves + 1;
        for(int i = 0; i < tam; i++)
        {
            if(strcmp(chave, temp1[i]) == 0)
            {
                printf("Essa chave já existe, não é possível realizar a inserção\n");
                break;
            }
            else if(strcmp(chave, temp1[i]) < 0)
            {
                
                strcpy(folha->chaves[i], chave);
                folha->dadosRRN[i] = RRN;
                
                for(int j = i+1; j < tam; j++)
                {
                    strcpy(folha->chaves[j], temp1[j-1]);
                    folha->dadosRRN[j] = RRNs[j-1];
                }
                folha->numeroChaves++;
                break;
            }
            else if(i + 1 == (tam - 1))
            {
                strcpy(folha->chaves[i+1], chave);
                folha->dadosRRN[i+1] = RRN;
                folha->numeroChaves++;
                break;
            }
        }
    }
    else
    {
        strcpy(folha->chaves[0], chave);
        folha->dadosRRN[0] = RRN;
        folha->numeroChaves++;
    }
}

node *busca_no(node *raiz, char *chave, FILE *fp)
{
    node *no_atual;
    char temp1[ordem][6];
    int RRNs[ordem], tam; 

    if(raiz->RRN == 0)
    no_atual = raiz;
    else
    no_atual = le_no(raiz->RRN, fp);

    while(no_atual->folha == 0)
    {
        for(int i = 0; i < no_atual->numeroChaves; i++)
        {
            strcpy(temp1[i], no_atual->chaves[i]);
            printf("%s ", temp1[i]);
        }

        for(int i = 0; i < no_atual->numeroChaves; i++)
        {
            if(strcmp(chave, temp1[i]) == 0)
            {
                no_atual = le_no(no_atual->filhos[i+1], fp);
                break;
            }
            else if(strcmp(chave, temp1[i]) < 0)
            {   
                printf("2 - ENtra aqui");
                //printf("Filhos: %d \n", no_atual->filhos[i]);
                no_atual = le_no((no_atual->filhos[i]), fp);
                //printf("%d ", no_atual->RRN);
                break;
            }
            else if(i+1 == no_atual->numeroChaves)
            {
                no_atual = le_no((no_atual->filhos[i+1]), fp);
                break;
            }
        }
    }

    return no_atual;
}

void inserir(char *chave, int RRN_dado, node **raiz, FILE *fp)
{
   node *no_antigo;

   no_antigo = busca_no((*raiz), chave, fp);
   printf("No antigo: %d\n", no_antigo->RRN); 
   insere_folha(no_antigo, chave, RRN_dado);

   if(no_antigo->numeroChaves == ordem)
   {
        node *novo_no = cria_no();
        novo_no->folha = 1;
        novo_no->pai = no_antigo->pai;
        int meio = (ordem/2);
        for(int i = meio; i < ordem; i++)
        {
            strcpy(novo_no->chaves[i-meio], no_antigo->chaves[i]);
            novo_no->dadosRRN[i-meio] = no_antigo->dadosRRN[i]; 

            strcpy(no_antigo->chaves[i], "#####");
            no_antigo->dadosRRN[i] = 0;
        }
        novo_no->numeroChaves = no_antigo->numeroChaves = ordem/2;
        novo_no->RRN = novo_RRN_no(fp);
        novo_no->prox = no_antigo->prox;
        no_antigo->prox = novo_no->RRN;
        escreve_no(no_antigo->RRN, no_antigo, fp);
        escreve_no(novo_no->RRN, novo_no, fp);
        getchar();
        //VER POSSIBILIDADE DE CRIAR NOVO NÓ COM RRN CERTO, OU SETAR DEPOIS(PARA NÃO ATRAPALHAR NO CADO DE NÓS AUXILIXARES)
        //ESCREVER OS NOVSO NÓS(COM AS CHAVES SEPARADAS) NO ARQUIVO AGORA?
        //ESCREVER O NÓ QUE RECEBE NOVA CHAVE QUANDO?
        //ACHO QUE REESCREVER NO ANTIGO E ESCREVER NOVO NÓ AGORA 
        //NA FUNÇÃO INSERIR NO PAI, ESCREVER A CADA CHAMADA RECURSIVA?
        
        insere_pai(no_antigo, novo_no->chaves[0], novo_no, raiz, fp);
   }
   else
   {
        escreve_no(no_antigo->RRN, no_antigo, fp);
        getchar();
   }
   //else -> escreve no arquivo
}

void insere_pai(node *no_antigo, char *chave_promovida, node *novo_no, node **raiz, FILE *fp)
{
    if((*raiz)->RRN == no_antigo->RRN)
    {
        node *nova_raiz = cria_no();
        strcpy(nova_raiz->chaves[0], chave_promovida);
        nova_raiz->numeroChaves = 1;
        nova_raiz->filhos[0] = no_antigo->RRN;
        nova_raiz->filhos[1] = novo_no->RRN;
        nova_raiz->RRN = novo_RRN_no(fp);
        *raiz = nova_raiz;
        no_antigo->pai = (*raiz)->RRN;
        novo_no->pai = (*raiz)->RRN;
        escreve_no(no_antigo->RRN, no_antigo, fp);
        escreve_no(novo_no->RRN, novo_no, fp);
        escreve_no((*raiz)->RRN, (*raiz), fp);
        getchar();

        //RRN DA NOVA RAIZ VAI PRECISAR SER SOBREESCRITO NO HEADER DO ARQUIVO
        //VERIFICAÇÃO NA MAIN-> SE ARQUIVO IBTREE NÃO EXISTE, RAIZ É 0 E CRIA PRIMEIRO NÓ
        return;
    }

    node *pai = le_no(no_antigo->pai, fp);
    int temp1[ordem];
    char temp2[ordem][6];
    int tam = pai->numeroChaves + 1;

    //printf("RNN nó antigo: %d", no_antigo->RRN);
    //printf("\nRRN no novo: %d", novo_no->RRN);
    for(int i = 0; i < tam; i++)
    {
        temp1[i] = pai->filhos[i];
        printf("%d ", temp1[i]);
    }
    
    
    for(int i = 0; i < tam - 1; i++)
    {
        strcpy(temp2[i], pai->chaves[i]);
        printf("%s ", temp2[i]);
    }
    
    printf("no antigo rrn: %d", no_antigo->RRN);

    for(int i = 0; i < tam; i++)
    {
        printf("entra aqui");
        printf("%d ", temp1[i]);
        if(temp1[i] == no_antigo->RRN)
        {
            printf("Entra aqui split i = %d", i);
            strcpy(pai->chaves[i], chave_promovida);
            pai->filhos[i+1] = novo_no->RRN;

            for(int j = i+1; j < tam; j++)
            {
                strcpy(pai->chaves[j], temp2[j-1]);
                pai->filhos[j+1] = temp1[j];
            }
            pai->numeroChaves++;
        }

        if(pai->numeroChaves == ordem)
        {
            node *outro_no = cria_no();
            outro_no->folha = 0;
            outro_no->pai = pai->pai;

            int meio = (ordem/2);
            for(int i = meio+1; i < ordem; i++)
            {
                strcpy(outro_no->chaves[i-(meio+1)], pai->chaves[i]);
                 

                strcpy(pai->chaves[i], "#####");
            }
            for(int i = meio+1; i< ordem + 1; i++)
            {
                outro_no->filhos[i-(meio+1)] = pai->filhos[i];
                pai->filhos[i] = 0;
            }
            strcpy(chave_promovida, pai->chaves[meio]);
            strcpy(pai->chaves[meio], "#####");
            pai->numeroChaves = ordem/2;
            outro_no->numeroChaves = (ordem/2) - 1;
            outro_no->RRN = novo_RRN_no(fp);
            
            for(int i = 0; i < pai->numeroChaves + 1; i++)
            {
                node *aux = le_no(pai->filhos[i], fp);
                aux->pai = pai->RRN;
            }

            for(int i = 0; i < outro_no->numeroChaves + 1; i++)
            {
                node *aux = le_no(outro_no->filhos[i], fp);
                aux->pai = outro_no->RRN;
            }
            escreve_no(pai->RRN, pai, fp);
            escreve_no(outro_no->RRN, outro_no, fp);

            insere_pai(pai, chave_promovida, outro_no, raiz, fp);
            //talvez reescrever os filhos aqui
        }
        else
        {
            escreve_no(pai->RRN, pai, fp);
            getchar();
            //talvez reescrever os filhos também
        }
    }
    //ACHO QUE ATÉ AQUI ESTÁ CERTO, CONFIRMAR DEPOIS 
    //RESOLVER QUESTÃO DE LIDA E ESCRITA NO ARQUIVO-> RRNS MAIORES QUE 9, VAI MUDAR O BYTEOFFSET
}