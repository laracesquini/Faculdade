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

void  insere_folha(no *folha, char *chave, int RRN)
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
                printf("Chega aqui");
                strcpy(folha->chaves[i+1], chave);
                folha->dadosRRN[i+1] = RRN;
                folha->numeroChaves++;
                break;
            }
            //testar isso depois
        }
    }
    
    
}