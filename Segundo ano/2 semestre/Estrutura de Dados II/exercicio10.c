#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main()
{
    FILE *fp, *write;
    int i = 0, j;
    //registro para salvar as informações
    typedef struct dados{
        char nome[40];
        float num_habitantes;
    }Tdados;

    Tdados cidades[MAX];
    Tdados maior;

    fp = fopen("arq.txt", "r");
    write = fopen("escrita.txt", "w");

    while(!feof(fp))
    {
        //ler o arquivo
        fscanf(fp, " %s", cidades[i].nome);
        fscanf(fp, " %f", &cidades[i].num_habitantes);

        i++;
    }
    
    //define uma cidade como a maior
    maior = cidades[0];

    for(j = 0; j<i; j++)
    {
        //comparar com as outras cidades e ver se tem uma maior que a atribuida inicialmente e, se tiver, essa é a nova cidade maior
        if(cidades[j].num_habitantes > maior.num_habitantes)
        {
            maior = cidades[j];
        }
        
    }

    //escrevendo no arquivo o resultado
    fprintf(write, "%s ", maior.nome);
    fprintf(write, "%.0f", maior.num_habitantes);

    //fechando os arquivos
    fclose(fp);
    fclose(write);
}