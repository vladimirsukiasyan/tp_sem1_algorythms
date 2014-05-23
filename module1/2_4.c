#include <stdio.h>
#define ERR_INPUT -1

void sumFractions(int, int, int, int, int *, int *);
int MCD(int, int);						//maximal common divider(НОД)

int main(void)
{
  int a, b, c, d, code = scanf("%d%d%d%d", &a, &b, &c, &d);
  if (code != 4)
    return ERR_INPUT;
  int e, f;
  sumFractions(a, b, c, d, &e, &f);
  printf("%d %d\n", e, f);
  return 0;
}

void sumFractions(int a, int b, int c, int d, int *commonNumerator, int *commonDenominator)
{
  *commonNumerator = a * d + b * c;
  *commonDenominator = b * d;
  int maxDiv = MCD(*commonNumerator, *commonDenominator);
  *commonNumerator /= maxDiv;
  *commonDenominator /= maxDiv;
}

int MCD(int a, int b)
{
  int c;
  while (b) {
      c = a % b;
      a = b;
      b = c;
   }
   return a;
}