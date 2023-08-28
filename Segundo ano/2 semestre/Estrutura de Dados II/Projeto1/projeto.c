#include <stdio.h>
#include "arquivos.h"

int main()
{
   FILE *fd, *fp, *fs;

   if(file_exists("dados.txt"))
   {
        fd = fopen("dados.txt", "a+");
   }
   else
   {
        fd = fopen("dados.txt", "w+");
   }
}