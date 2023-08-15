#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 5

//struct com os dados dos alunos
typedef struct aluno {
    char nome[50];
    char curso[30];
    char ano[5];
    char email[50];
    int nro_UNESP;
}Taluno;

//struct com a chave primária e seu respectivo índice
typedef struct ind{
    int nro_UNESP;
    int indice;
}Tindice;

//funções utilizadas. Ordenação e busca binária
void ordenar(Tindice *indice);
int busca_binaria(Tindice *indice, int num);

int main()
{
    Taluno alunos[n];
    Tindice indice[n];
    int i, nmr_buscado;
    char linha[135];
    char campos[4][20] = {"Nome: ", "Curso: ", "Ano: ", "Email: "};
    FILE *dados, *indices;

    //abrindo os arquivos
    dados = fopen("dados.txt", "w");
    indices = fopen("indices.txt", "w");

    for(i = 0; i<n; i++)
    {
        //Coletando os dados do usuário
        printf("Aluno %d\n", i+1);
        printf("Digite o nome: ");
        scanf(" %[^\n]s", alunos[i].nome);
        printf("Digite o curso: ");
        scanf(" %[^\n]s", alunos[i].curso);
        printf("Digite o ano: ");
        scanf(" %[^\n]s", alunos[i].ano);
        printf("Digite o email: ");
        scanf(" %[^\n]s", alunos[i].email);
        printf("Digite o número UNESP: ");
        scanf(" %d", &alunos[i].nro_UNESP);

        //uso da função ftell(diz onde está o ponteiro) para a atribuição do índice
        indice[i].nro_UNESP = alunos[i].nro_UNESP;
        indice[i].indice = ftell(dados);

        //organizando o arquivo usando separação de campos e registros por delimitadores
        fprintf(dados, "%s|%s|%s|%s|%d#", alunos[i].nome, alunos[i].curso, alunos[i].ano, alunos[i].email, alunos[i].nro_UNESP);
    }

    //ordenar os índices para facilitar a busca
    ordenar(indice);

    //arquivo em que ficará salvo os índices e suas chaves primárias
    for(i = 0; i < n; i++)
    {
        fprintf(indices, "%d|%d|",indice[i].nro_UNESP, indice[i].indice);
    }

    fclose(dados);
    fclose(indices);
    
    //Requisitando a chave primária do aluno buscado
    printf("Busca: \n");
    printf("Digite o número UNESP do aluno: ");
    scanf("%d", &nmr_buscado);

    //busca binária pela chave, retornando o índice do registro buscado
    nmr_buscado = busca_binaria(indice, nmr_buscado);

    //verificando se o registro foi encontrado
    if(nmr_buscado != -1)
    {
        printf("Aluno encontrado! Dados: \n");
        dados = fopen("dados.txt", "r");
        fseek(dados, indice[nmr_buscado].indice, SEEK_SET);
        fscanf(dados, " %[^#]s", linha);
        char *token = strtok(linha, "|"); //separando os campos dos registros

        i = 0;
        while(token != NULL && i < 4)
        {
            printf(campos[i]);
            printf("%s\n", token);
            token = strtok(NULL, "|");
            i++;
        }
    }
    else
    printf("Não encontrado\n");
}

//ordenação por Insertion Sort
void ordenar(Tindice *indice)
{
    for(int i = 1; i < n; i++)
    {
        int j = i;

        while(j > 0 && indice[j].nro_UNESP < indice[j-1].nro_UNESP)
        {
            Tindice aux = indice[j];
            indice[j] = indice[j-1];
            indice[j-1] = aux;
            j-=1;
        }
    }
}

//Busca binária
int busca_binaria(Tindice *indice, int num)
{
    int min = 0, max = (n-1), mid;

    while(min <= max)
    {
        mid = (min + max)/2;

        if(num == indice[mid].nro_UNESP)
        return mid;
        else if(num > indice[mid].nro_UNESP)
        min = mid + 1;
        else
        max = mid - 1;
    }

    return -1;
}