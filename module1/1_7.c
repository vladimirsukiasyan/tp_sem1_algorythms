#include <stdio.h>
#define ERR_INPUT -1

int reverse(int);

int main(void)
{
  int num_to_reverse, code = scanf("%d", &num_to_reverse);
  if (code != 1)
    return ERR_INPUT;
  
  printf("%d\n", reverse(num_to_reverse));
  return 0;
}

int reverse(int num)
{
  int num_reversed = 0;
  while (num)
  {
    num_reversed = num_reversed * 10 + num % 10;
    num /= 10;
  }
  return num_reversed;
}