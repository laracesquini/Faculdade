#include <stdio.h>

int main()
{
  int i;

  i=1;
  
  while(i>=1 && i<=200) 
  {
    if((i/4)*4==i) 
    {
        printf("%d é divisível por 4", i);
    }
    else
        printf("\n");
    i++;
  }
  
    return 0;
}