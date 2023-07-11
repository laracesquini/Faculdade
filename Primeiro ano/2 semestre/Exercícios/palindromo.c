#include <stdio.h>
#include <string.h>

int palindromo(char *palavra, int i, int tam);
int palindromeio(char *palavra, int tam);

int main()
{
    int tam=0, i=0;
    char palavra[2001];

    //printf("Digite uma palavra: ");
    scanf(" %s", palavra);

    tam = strlen(palavra);

    printf("%d", palindromeio(palavra, tam));

    return 0;
}

int palindromo(char *palavra, int i, int tam)
{
    if(i> tam/2)
    return 1;
    else
    {
        if(palavra[i] != palavra[tam-1-i])
        return 0;
        else
        return palindromo(palavra, i+1, tam);
    }
}

int palindromeio(char *palavra, int tam)
{
    int i, j, k, count;
    char nome[tam];

    for(i=tam; i>0; i--)
    {
      
      for(j=0; j<tam+1-i; j++)
        {
            count = 0;
            for(k=j; k<i+j; k++)
            {
                nome[count] = palavra[k];
                count++;
            }
            nome[count] = '\0';
            if(palindromo(nome, 0, i)==1)
            return i;
        }
    }
}