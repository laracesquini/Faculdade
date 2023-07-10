#include <stdio.h>

int main()
{
  int post, termo, ant, i;

  i=15;
  ant=0;
  post=1;
  
  while(i>0)
  {
    termo=post-ant;
    printf("%d ", termo);
    post=post+termo;
    ant=termo++;
    i--;
    }
    
  return 0;
}
