#include <stdio.h>
#define ERR_INPUT -1

int mod(int, int);

int main(void) {
  int a, b, code;
  code = scanf("%d%d", &a, &b);
  if ((code != 2) || (b == 0))
    return ERR_INPUT;
  printf("%d\n", mod(a, b));
  return 0;
}

int mod(int a, int b)
{
  while (a >= b)
    a -= b;      
  return a;
}