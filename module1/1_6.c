#include <stdio.h>
#define ERR_INPUT -1

int factArg(int);

int main(void)
{
  int fact, code = scanf("%d", &fact);
  if (code != 1)
    return ERR_INPUT;
  printf("%d\n", factArg(fact));
  return 0;
}

int factArg(int fact)
{
  int fact_arg = 1;
  while (fact != 1)
    fact /= ++fact_arg;
  return fact_arg;
}