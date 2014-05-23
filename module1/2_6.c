#include <stdio.h>
#define ERR_INPUT -1

void printSquares(int);

int main(void)
{
  int n;
  int code = scanf("%d", &n);
  if (code != 1)
    return ERR_INPUT;
  
  printSquares(n);
  return 0;  
}

void printSquares(int n)
{
  int i, square, partSum;
  for (i = 1, square = 1, partSum = 1; i <= n; ++i)
  {
    printf("%d ", square);
    partSum += 2;
    square += partSum;
  }
  putchar('\n');
}