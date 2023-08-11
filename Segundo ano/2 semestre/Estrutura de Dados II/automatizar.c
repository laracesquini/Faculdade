#include <stdio.h>
#include <stdlib.h>
#define n 2

typedef struct aluno {
    char nome[50];
    char curso[30];
    char ano[5];
    char email[50];
    int nro_UNESP;
}Taluno;

typedef struct ind
{
    int nro_UNESP;
    int indice;
}Tindice;

void ordenar(Tindice *indice);
int busca_binaria(Tindice *indice, int num);

int main()
{
    Taluno alunos[n];
    Tindice indice[n];
    int i, nmr_buscado;
    char nome[50], curso[50], ano[5], email[50], linha[2000];
    FILE *dados, *indices;
    dados = fopen("dados.txt", "w");
    indices = fopen("indices.txt", "w");

    for(i = 0; i<n; i++)
    {
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

        indice[i].nro_UNESP = alunos[i].nro_UNESP;
        indice[i].indice = ftell(dados);

        fprintf(dados, "%s|%s|%s|%s|%d#", alunos[i].nome, alunos[i].curso, alunos[i].ano, alunos[i].email, alunos[i].nro_UNESP);
    }

    ordenar(indice);

    for(i = 0; i < n; i++)
    {
        fprintf(indices, "%d|%d|",indice[i].nro_UNESP, indice[i].indice);
    }

    fclose(dados);
    fclose(indices);

    printf("Busca: \n");
    printf("Digite o número UNESP do aluno: ");
    scanf("%d", &nmr_buscado);

    nmr_buscado = busca_binaria(indice, nmr_buscado);

    if(nmr_buscado != -1)
    {
        dados = fopen("dados.txt", "r");
        fseek(dados, indice[nmr_buscado].indice, SEEK_SET);
        fscanf(dados, "%[^#]s", linha);
        while(fgetc(dados) != '#') //ver isso depois, não está funcionando
        {
            fscanf(dados, "%[^|]s", nome);
            printf("%s\n", nome);
        }
    }
    else
    printf("Não encontrado\n");
}

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

int busca_binaria(Tindice *indice, int num)
{
    int min = 0, max = (n-1), mid;

    if(num == indice[min].nro_UNESP)
    return min;
    if(num == indice[max].nro_UNESP)
    return max;

    mid = (min+max)/2;

    while(num != indice[mid].nro_UNESP && min < max)
    {
        if(num > indice[mid].nro_UNESP)
        min = mid;
        else
        max = mid;

        mid = (max+min)/2;
    }

    if(num != indice[mid].nro_UNESP)
    return -1;
    else
    return mid;
}