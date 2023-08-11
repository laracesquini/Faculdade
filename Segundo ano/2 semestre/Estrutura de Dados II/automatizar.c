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

int main()
{
    

    Taluno alunos[n];
    Tindice indice[n];
    int i;
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

        fprintf(dados, "%s|%s|%s|%s|%d|", alunos[i].nome, alunos[i].curso, alunos[i].ano, alunos[i].email, alunos[i].nro_UNESP);
    }

    ordenar(indice);

    for(i = 0; i < n; i++)
    {
        fprintf(indices, "%d|%d|",indice[i].nro_UNESP, indice[i].indice);
    }

    fclose(dados);
    fclose(indices);
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