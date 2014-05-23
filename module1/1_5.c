#include <stdio.h>
#define ERR_INPUT -1

int div(int, int);

int main(void) {
  int a, b, code;            //c = a/b
  code = scanf("%d%d", &a, &b);
  
  if ((code != 2) || (b == 0))
    return ERR_INPUT;
  
  printf("%d\n", div(a, b));
  
  return 0;
}

int div(int a, int b)
{
  int c = 0;
  while (a >= b)
  {
    a -= b;      
    ++c;
  }
  return c;
}