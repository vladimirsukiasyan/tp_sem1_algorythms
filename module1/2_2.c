#include <stdio.h>
#define ERR_INPUT -1

void printSimpleMultipliers(int);

int main(void)
{
  int num_to_simple, code = scanf("%d", &num_to_simple);
  if (code != 1)
    return ERR_INPUT;
  printSimpleMultipliers(num_to_simple);
  return 0;
}

void printSimpleMultipliers(int n)
{
  int simple;
  for (simple = 2; simple <= (n / 2); ++simple)
    while ((n % simple) == 0)
    {
      printf("%d ", simple);
      n /= simple;
    }
    if (n > 1)
      printf("%d", n);
  putchar('\n');
}