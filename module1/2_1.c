#include <stdio.h>
#define ERR_INPUT -1

int zeroInFact(int arg);
int fivesIn(int n);

int main(void)
{
  int fact_arg, code = scanf("%d", &fact_arg);
  if (code != 1)
    return ERR_INPUT;
  printf("%d\n", zeroInFact(fact_arg));
  return 0;
}

int zeroInFact(int arg)
{
  int zero_counter = 0;
  int i;
  for (i = 0; i <= arg; ++i)
    zero_counter += fivesIn(i);
  return zero_counter;
}

int fivesIn(int n)
{
  int i = 0;
  while(n && ((n % 5) == 0))
  {
    n /= 5;
    ++i;
  }
  return i;
}