#include <stdio.h>
#include <string.h>
#define MAX 100

void clean(char*);
int decimal (char*);
void romano(int*, char*);

int main()
{
    char roma[MAX], roman[MAX];
    int  i, N, C, romano_total=0, inteiro;

    scanf("%d", &N);

    for(i=0; i<N; i++)
    {
        scanf("%d", &C);
        if(C==1)
        {
            scanf(" %s", roma);
            printf("%d\n", decimal(roma));
            romano_total = romano_total + decimal(roma);
        }
        else
        {
            clean(roman);
            scanf("%d", &inteiro);
            romano(&inteiro, roman);
            printf("%s\n", roman);
        }
    }
    printf("%d", romano_total);

    return 0;
}

void clean (char *roman)
{
    int i;
    for(i=0; i<MAX; i++)
    {
        roman[i] = '\0';
    }
}

int decimal (char *roma)
{
    int  i, j, valor[MAX], total=0, sub=0;
    
    for(i=0; i<MAX; i++)
    {
        valor[i]= 0;
    }
    for(i=0; i<strlen(roma); i++)
    {
        if(roma[i]=='I')
        valor[i] = 1;
        else if(roma[i]=='V')
        valor[i] = 5;
        else if(roma[i]=='X')
        valor[i] = 10;
        else if(roma[i]=='L')
        valor[i] = 50;
        else if(roma[i]=='C')
        valor[i] = 100;
        else if(roma[i]=='D')
        valor[i] = 500;
        else 
        valor[i]= 1000;
    }
    for(i=0; i<strlen(roma); i++)
    {
        if(valor[i]<valor[i+1])
        {
            sub = valor[i+1]-valor[i];
            i++;
        }
        else
        sub = valor[i];
        
        total = total + sub;
    }

    return total;
}

void romano (int *decimal, char *roman)
{
    int MCDU[4], i;
    char *poss[4][4] = {{"M"},
                        {"C", "CD", "D", "CM"},
                        {"X", "XL", "L", "XC"},
                        {"I", "IV", "V", "IX"}
                       };
    
    MCDU[0] = *decimal/1000;
    MCDU[1] = (*decimal % 1000)/100;
    MCDU[2] = (*decimal % 100)/10;
    MCDU[3] = (*decimal % 10)/1;
    
    for(i=0; i<4; i++)
    {
        while(MCDU[i]!=0)
        {
            if(MCDU[i]==1 || MCDU[i]==2 || MCDU[i]==3)
            {
                strcat(roman, poss[i][0]);
                MCDU[i] = MCDU[i] - 1;
            }
            if(MCDU[i]==4)
            {
                strcat(roman, poss[i][1]);
                MCDU[i] = MCDU[i] - 4; 
            }
            if(MCDU[i]==5 || MCDU[i]==6 || MCDU[i]==7 || MCDU[i]==8)
            {
                strcat(roman, poss[i][2]);
                MCDU[i] = MCDU[i] - 5;
            }
            if(MCDU[i] == 9)
            {
                strcat(roman, poss[i][3]);
                MCDU[i] = MCDU[i] - 9;
            }
        }
    }
}