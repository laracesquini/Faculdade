#include <stdio.h>

int main()
{
  int a, f, anos;
  
  a=150;
  f=110;
  anos=0;

  while(f<a) 
  {
    a+=2;
    f+=3;
    anos++;
  }
  
  printf("%d anos", anos);
  
  return 0;
}