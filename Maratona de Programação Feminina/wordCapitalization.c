#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char string[1000];

    scanf("%s", string);

    string[0] = toupper(string[0]);

    printf("%s", string);
}