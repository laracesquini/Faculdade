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
    else if(strcmp(p->titulo, aux->titulo)>0) //insere como último elemento
    {
        p->prox = aux->prox;
        aux->prox = p;
        return h;
    }
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
void cria_indices(FILE *fd, FILE *fs,  Isecundario *vets,  int flags)
{
    char aux[193], *token;
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
    salvar(fs, vets, flags);
    
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
    
    novo = (novo/192);

    return novo;
}

//função que salva os índices no arquivo
void salvar(FILE *fs, Isecundario *vets, int flags)
{
    Isecundario *auxs;

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

//função que busca um registro pela chave primária, retorna o RRN do elemento no arquivo de dados ou -1, caso não seja encontrado
int busca(node *raiz, char *chave, FILE *fp)
{
    node *no;

    //usa a função busca_no para encontrar o nó folha em que a chave está ou deveria estar
    no = busca_no(raiz, chave, fp);

    for(int i = 0; i<no->numeroChaves; i++)
    {   
        //verifica se a chave está no nó e se estiver, retorna o RRN associado a ela
        if(strcmp(no->chaves[i], chave) == 0)
        return no->dadosRRN[i];
    }

    return -1;
}

//função que atualiza a nota no arquivo de dados
void att_arquivo(FILE *fd, int RRN, char *nota)
{
    int byte_offset = 192*RRN, count;
    char c;

    count = 0;
    fd = fopen("movies.dat", "r+");
    
    //encontra a posição do registro no arquivo, usando o RRN
    fseek(fd, byte_offset, SEEK_SET);
    //encontra o campo referente a nota
    while(count < 7)
    {
        c = fgetc(fd);
        if(c == '@')
        count++;
    }

    //atualiza a nota
    fseek(fd, -2, SEEK_CUR);
    fprintf(fd, "%s", nota);

    fclose(fd);

    return;
}

//função que imprime o filme buscado pelo usuário
void imprime_filme(int RRN, FILE *fd)
{
    int byte_offset = 192*RRN;
    char filme[193], *token;
    char campos[7][50] = {"Chave: ", "Nome em português: ", "Nome original: ", "Diretor: ", "Ano de lançamento: ", "País: ", "Nota: "};
    
    fd = fopen("movies.dat", "r");

    //encontra o registro e printa todas as informações
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
void busca_secundario(node *raiz, Isecundario *vets , char *titulo, FILE *fd, FILE *fp)
{
    Isecundario *auxs;
    int stt = 0, RRN_buscado;

    auxs = vets;
    
    //percorre a lista até encontrar o filme referente ao título digitado
    while(auxs != NULL)
    {
        //Se encontrar, busca o RRN do filme usando a chave primária e imprime o filme
        if(strcmp(auxs->titulo, titulo) == 0)
        {
            stt = 1;
            RRN_buscado = busca(raiz, auxs->first_key, fp);
            imprime_filme(RRN_buscado, fd);
            auxs = auxs->prox;
        }
        else
        auxs = auxs->prox;
    }

    if(stt == 0)
    printf("Filme não encontrado!\n");
}

//função que printa o catálogo 
void catalogo(FILE *fd, FILE *fp, int RRN_inicio, int operacao, char *chave)
{
    int i, stt = 0;
    node *aux;

    //Imprime todos os filmes a partir de uma dada chave
    if(operacao == 1)
    {
        //le o nó que contém a chave e encontra em que posição ela está
        aux = le_no(RRN_inicio, fp);

        for(i = 0; i < aux->numeroChaves; i++)
        {
            if(strcmp(aux->chaves[i], chave) == 0)
            {
                stt = 1;
                break;
            }
        }

        if(stt == 0)
        {
            printf("Essa chave não foi encontrada!\n");
            return;
        }
        else
        {
            //printa todas as chaves presentes naquele nó
            for(int k = i; k < aux->numeroChaves; k++)
            imprime_filme(aux->dadosRRN[k], fd);
        }

        //para todos os outros nós folhas, avança pela lista printando todos os filmes
        while(aux->prox != 0)
        {
            aux = le_no(aux->prox, fp);
            for(int k = 0; k < aux->numeroChaves; k++)
            imprime_filme(aux->dadosRRN[k], fd);
        }
    }
    else //imprime todos os filmes ordenados pela chave primária
    {
        //lê o primeiro nó folha, que está no começo da lista e printa todas as chaves dele, fazendo isso para todos os nós da lista
        aux = le_no(RRN_inicio, fp);
        for(int k = 0; k < aux->numeroChaves; k++)
        imprime_filme(aux->dadosRRN[k], fd);

        while(aux->prox != 0)
        {
            aux = le_no(aux->prox, fp);
            for(int k = 0; k < aux->numeroChaves; k++)
            imprime_filme(aux->dadosRRN[k], fd);
        }
    }
    
    return;
}

//função que busca o início da lista composta por todos os nós folhas, descendo sempre para a esquerda a partir da raiz
node *busca_inicio(node *raiz, FILE *fp)
{
    node *no_atual;

    if(raiz->RRN == 0)
    no_atual = raiz;
    else
    no_atual = le_no(raiz->RRN, fp);

    while(no_atual->folha == 0)
    {
        no_atual = le_no(no_atual->filhos[0], fp);
    }

    return no_atual;
}

//função que escreve o nó no arquivo que contém a árvore B+
void escreve_no(int RRN, node *no, FILE *fp)
{
    int byte_offset = (192*RRN);
    char aux[6];
    
    //posiciona o ponteiro no lugar certo a ser escrito e escreve todas as informações
    fp = fopen("ibtree.idx", "r+");
    fscanf(fp, " %[^@]s", aux);
    fgetc(fp);

    fseek(fp, byte_offset, SEEK_CUR);
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

    //preenche o espaço que faltou com o caracter '#'
    int escrito, falta, posicao_atual = ftell(fp);
    escrito = posicao_atual - (192*RRN) - 6;
    falta = 192 - escrito;

    for(int i =0; i < falta; i++)
    {
        fputc('#', fp);
    }
    fclose(fp);
}

//função que lê um nó do arquivo que contém a árvore B+
node *le_no(int RRN, FILE *fp)
{
    node *no_lido;
    int byte_offset = (192*RRN);
    char linha[100], aux[6], *aux1, *aux2, *aux3, *aux4, *aux5, *aux6;

    //posiciona o ponteiro no lugar certo a ser lido
    fp = fopen("ibtree.idx", "r");
    fscanf(fp, " %[^@]s", aux);
    fgetc(fp);
    fseek(fp, byte_offset, SEEK_CUR);
    
    //lê todo o registro, salvando-o em uma string e vai separando as informações, colocando-as na variável do tipo node
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
    return no_lido; //retorna o nó lido
}

//função que cria e inicializa um nó genérico
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

//função que encontra o RRN do novo nó que será escrito no arquivo de dados
int novo_RRN_no(FILE *fp)
{
    int novo;

    fp = fopen("ibtree.idx", "r");

    fseek(fp, 0, SEEK_END);
    novo = ftell(fp);

    fclose(fp);
    
    novo = (novo/192);

    return novo;
}

//função que atualiza o cabeçalho do arquivo que contém a árvore B+ quando a raiz for criada ou mudar
void att_raiz(int RRN, FILE *fp, int flag)
{
    char *str = (char *)malloc(6);

    //transformando o RRN da raiz em uma string de tamanho fixo
    sprintf(str, "%d", RRN);

    int len = strlen(str);

    for(int i = len; i < 5; i++)
    {
        str[i] = '#';
    }

    str[5] = '\0';

    if(flag == 0) //primeira inserção, escrever a raiz no arquivo, tendo RRN = 0
    {
        fp = fopen("ibtree.idx", "w");
        fprintf(fp, "%s", str);
        fputc('@', fp);
        fclose(fp);
    }
    else //atualizar a raiz, lendo a raiz antiga e escrevendo a atual
    {
        char aux[6];
        fp = fopen("ibtree.idx", "r+");
        fscanf(fp, " %[^@]s", aux);
        fgetc(fp);
        fseek(fp, 0, SEEK_SET);
        fprintf(fp, "%s", str);
        fputc('@', fp);
        fclose(fp);
    }
   
    return;
}

//função que insere uma chave em um nó folha
int insere_folha(node *folha, char *chave, int RRN)
{
    //verifica se o nó está vazio
    if(folha->numeroChaves != 0)
    {
        char temp1[ordem][6]; 
        int RRNs[ordem], tam; 

        for(int i = 0; i < folha->numeroChaves; i++) //copias todas as chaves presentes no nó para um vetor auxiliar, assim como seus RRNs
        {
            strcpy(temp1[i], folha->chaves[i]);
            RRNs[i] = folha->dadosRRN[i];
        }

        tam = folha->numeroChaves + 1;
        for(int i = 0; i < tam; i++)
        {
            if(strcmp(chave, temp1[i]) == 0) //se a chave já existir, não insere
            {
                printf("Essa chave já existe, não é possível realizar a inserção\n");
                return -1;
            }
            else if(strcmp(chave, temp1[i]) < 0) //se a chave a ser inserida for menor que a chave atual
            {
                //insere a chave na posição i e copia as chaves a partir dessa posição para um posição a direita, assim como os RRNs
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
            else if(i + 1 == (tam - 1)) //se a chave a ser inserida for maior que todas as chaves presentes no nó, insere ela na última posição, assim como o RRN
            {
                strcpy(folha->chaves[i+1], chave);
                folha->dadosRRN[i+1] = RRN;
                folha->numeroChaves++;
                break;
            }
        }
    }
    else //se o nó estiver vazio, insere a chave e seu  RRN na primeira posição
    {
        strcpy(folha->chaves[0], chave);
        folha->dadosRRN[0] = RRN;
        folha->numeroChaves++;
    }

    return 1;
}

//função que busca o nó em que uma chave deve ser inserida
node *busca_no(node *raiz, char *chave, FILE *fp)
{
    node *no_atual;
    char temp1[ordem][6];
    int RRNs[ordem], tam; 

    //lê a raiz da árvore
    if(raiz->RRN == 0)
    no_atual = raiz;
    else
    no_atual = le_no(raiz->RRN, fp);

    //enquanto o nó atual for interno, continua a busca
    while(no_atual->folha == 0)
    {
        for(int i = 0; i < no_atual->numeroChaves; i++)
        {
            strcpy(temp1[i], no_atual->chaves[i]);
        }

        for(int i = 0; i < no_atual->numeroChaves; i++)
        {
            if(strcmp(chave, temp1[i]) == 0) //se a chave a ser inserida for igual a uma chave presente em um nó interno, descer para o filho direito do nó atual
            {
                no_atual = le_no(no_atual->filhos[i+1], fp);
                break;
            }
            else if(strcmp(chave, temp1[i]) < 0) //se a chave a ser inserida for menor que uma chave presente em um nó interno, descer para o filho esquerdo do no atual
            {   
                no_atual = le_no((no_atual->filhos[i]), fp);
                break;
            }
            else if(i+1 == no_atual->numeroChaves) //se a chave a ser inserida for maior que todas as chaves presentes em um nó interno, descer para o filho direito do no atual
            {
                no_atual = le_no((no_atual->filhos[i+1]), fp);
                break;
            }
        }
    }

    return no_atual;
}

//função que insere uma chave na árvore B+
int inserir(char *chave, int RRN_dado, node **raiz, FILE *fp)
{
   node *no_antigo;

   //busca o nó folha em que a chave deve ser inserida e insere
   no_antigo = busca_no((*raiz), chave, fp);
   int flag = insere_folha(no_antigo, chave, RRN_dado);

   //verifica se a chave foi inserida corretamente
   if(flag == 1)
   {
        if(no_antigo->numeroChaves == ordem) //verifica se é necessário realizar um split, ou seja, com a inserção da nova chave, o número máximo de chaves foi ultrapassado
        {
            node *novo_no = cria_no(); //cria um novo nó, setando suas informações e redistribui as chaves
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
            escreve_no(no_antigo->RRN, no_antigo, fp); //escreve o nó antigo alterado e o novo nó no arquivo
            escreve_no(novo_no->RRN, novo_no, fp);
            
            insere_pai(no_antigo, novo_no->chaves[0], novo_no, raiz, fp); //chama a função para inserir a chave promovida no nó pai
        }
        else //se não houver necessidade de split, somente escreve a atualização feita no arquivo
        {
            escreve_no(no_antigo->RRN, no_antigo, fp);
        }
        return flag;
    }
    else
    return flag;
}

//função que insere uma chave promovida em um nó
void insere_pai(node *no_antigo, char *chave_promovida, node *novo_no, node **raiz, FILE *fp)
{
    //verifica se o nó antigo era a raiz, se for o caso, é preciso criar uma nova raiz
    if((*raiz)->RRN == no_antigo->RRN)
    {
        node *nova_raiz = cria_no(); //cria a raiz e seta suas informações
        strcpy(nova_raiz->chaves[0], chave_promovida); //copia a chave promovida para a raiz
        nova_raiz->numeroChaves = 1;
        nova_raiz->filhos[0] = no_antigo->RRN;
        nova_raiz->filhos[1] = novo_no->RRN;
        nova_raiz->RRN = novo_RRN_no(fp);
        *raiz = nova_raiz;
        no_antigo->pai = (*raiz)->RRN;
        novo_no->pai = (*raiz)->RRN;
        
        escreve_no(no_antigo->RRN, no_antigo, fp); //escreve as mudanças no arquivo
        escreve_no(novo_no->RRN, novo_no, fp);
        escreve_no((*raiz)->RRN, (*raiz), fp);

        att_raiz((*raiz)->RRN, fp, 1); //atualiza o RRN da raiz presente no cabeçalho do arquivo de dados
        return;
    }

    node *pai = le_no(no_antigo->pai, fp); //caso o antigo nó não seja a raiz, carrega seu pai, onde será inserida a chave promovida
    int temp1[ordem];
    char temp2[ordem][6];
    int tam = pai->numeroChaves + 1;

    for(int i = 0; i < tam; i++)
    temp1[i] = pai->filhos[i];
    
    for(int i = 0; i < tam - 1; i++)
    strcpy(temp2[i], pai->chaves[i]);
        
    for(int i = 0; i < tam; i++)
    {
        if(temp1[i] == no_antigo->RRN) //encontra onde a chave deve ser inserida
        {
            strcpy(pai->chaves[i], chave_promovida); //copia a chave para a posição adequada e reorganiza as outras, assim como os filhos
            pai->filhos[i+1] = novo_no->RRN;

            for(int j = i+1; j < tam; j++)
            {
                strcpy(pai->chaves[j], temp2[j-1]);
                pai->filhos[j+1] = temp1[j];
            }
            pai->numeroChaves++;
        }

        //verifica se, com essa nova inserção, é necessário realizar um split no nó pai
        if(pai->numeroChaves == ordem)
        {
            node *outro_no = cria_no(); //cria um novo nó setando suas informações
            outro_no->folha = 0;
            outro_no->pai = pai->pai;

            int meio = (ordem/2);
            for(int i = meio+1; i < ordem; i++) //redistribui as chaves e os filhos
            {
                strcpy(outro_no->chaves[i-(meio+1)], pai->chaves[i]);
                 

                strcpy(pai->chaves[i], "#####");
            }
            for(int i = meio+1; i < ordem + 1; i++)
            {
                outro_no->filhos[i-(meio+1)] = pai->filhos[i];
                pai->filhos[i] = 0;
            }
            strcpy(chave_promovida, pai->chaves[meio]);
            strcpy(pai->chaves[meio], "#####");
            pai->numeroChaves = ordem/2;
            outro_no->numeroChaves = (ordem/2) - 1;
            outro_no->RRN = novo_RRN_no(fp);
            
            for(int i = 0; i < pai->numeroChaves + 1; i++) //atualiza o pai dos nós que agora tem o nó criado como pai
            {
                node *aux = le_no(pai->filhos[i], fp);
                aux->pai = pai->RRN;
                escreve_no(aux->RRN, aux, fp);
            }

            for(int i = 0; i < outro_no->numeroChaves + 1; i++)
            {
                node *aux = le_no(outro_no->filhos[i], fp);
                aux->pai = outro_no->RRN;
                escreve_no(aux->RRN, aux, fp);
            }
            escreve_no(pai->RRN, pai, fp); //escreve as mudanças no arquivo
            escreve_no(outro_no->RRN, outro_no, fp);

            insere_pai(pai, chave_promovida, outro_no, raiz, fp); //chama a função recursivamente para repetir o processo
        }
        else //caso o split não seja necessário, somente escreve as mudanças do nó pai no arquivo
        escreve_no(pai->RRN, pai, fp);
    }
}