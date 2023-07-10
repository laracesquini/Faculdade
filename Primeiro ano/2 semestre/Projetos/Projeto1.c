//Inclusão das bibliotecas usadas
#include <stdio.h>
#include <math.h>

//Programa principal
int main()
{
    //Declaração das variáveis usadas
    int N, i, count1, count2=0;
    char str_aux[100], c;
    FILE *fp, *fc, *fl;
    
    //Abrindo os arquivos
    fp = fopen("palavras.dat", "r");
    fc = fopen("codigos.dat", "r");
    fl = fopen("linhas.dat", "w");

    //Laço que percorre os arquivos que serão lidos até que um deles, ou os dois, cheguem ao final
    while(!feof(fc) && !feof(fp))
    {
        //Ler um número em codigos.dat e salvar na variável N
        fscanf(fc, "%d", &N);
        //Se N for positivo
        if(N>0)
        {
            for(i=0; i<N; i++)
            {
                //Laço para ler em palavras.dat a quantidade de palavras indicadas por N e escrever em letras.dat
                fscanf(fp, " %s", str_aux);
                fprintf(fl, "%s ", str_aux);
            }
            fprintf(fl, "\n"); //Pular para a linha debaixo
            
        }
        //Se N for igual a 0
        else if(N==0)
        {
            //Escrever em letras.dat um único número 0 e pular para a linha debaixo
            fprintf(fl, "%d\n", N);
        }
        //Se N for negativo
        else if(N<0)
        {
            //Inicializando um contador como 0
            count1 = 0;
            //Laoço para voltar a quantidade de palavras indicadas por N
            while(count1<fabs(N))
            {
                fseek(fp, -1, SEEK_CUR); //Redireciona o ponteiro para 1 posição anterior a partir da atual
                fscanf(fp, "%c", &c); //Ler o caractere e salvar na variável c
                if(c == ' ') //Se o caractere salvo for um espaço, significa que voltamos 1 palavra, incrementa o contador
                {
                    count1++;
                }
                fseek(fp, -1, SEEK_CUR); //Como voltamos um caractere mas depois lemos ele, é preciso voltar novamente
            }
            //Ao sair desse laço, temos o ponteiro exatamente onde queremos(posição indicada por N) e podemos ler as palavras a partir daí
            for(i=0; i<fabs(N); i++)
            {
                fscanf(fp, " %s", str_aux);
                fprintf(fl, "%s ", str_aux);
            }
            fprintf(fl, "\n");
        }
    }
    //Se o arquivo de codigos não tiver terminado, mas o de palavras sim, fazer um laço para percorrer o arquivo de códigos até o fim e escrever os números em uma linha de linhas.dat
    if(!feof(fc) && feof(fp))
    {
        while(!feof(fc))
        {
            fscanf(fc, "%d", &N);
            fprintf(fl, "%d ", N);
        }
    }
    //Se o arquivo de palavras não tiver terminado, mas o de códigos sim, fazer um laço para percorrer o arquivo de palavras até o fim e escrever até 5 palavras por linha em linhas.dat
    if(feof(fc) && !feof(fp))
    {
        while(!feof(fp))
        {
            fscanf(fp, " %s", str_aux);
            fprintf(fl, "%s ", str_aux);
            count2++; //contador para auxíliar na contagem de palavras
            if(count2==5) //quando o contador contar 5 palavras, pular para a linha debaixo e zera o contador, para repetir o processo na próxima linha 
            {
                fprintf(fl, "\n");
                count2 = 0;
            }
        }
    }

    //Fechando os arquivos
    fclose(fp);
    fclose(fc);
    fclose(fl); 
}