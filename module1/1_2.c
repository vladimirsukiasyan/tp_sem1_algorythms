#include <stdio.h>
#define ERR_INPUT -1

int insertableRect(int, int, int, int);

int main(void)
{
  int a, b, c, d;
  int code;
  code = scanf("%d%d%d%d", &a, &b, &c, &d);
    if ((code != 4) || (b == 0))
    return ERR_INPUT;
    
  if (insertableRect(a, b, c, d))
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}

int insertableRect(int a, int b, int c, int d)
{
  return (((a >= c) && (b >= d)) || ((a >= d) && (b >= c))) ? 1 : 0;    
}