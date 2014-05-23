#include <stdio.h>
#define ERR_INPUT -1

int countOnes(int);

int main(void)
{
    int n, code;
    code = scanf("%d", &n);
    if (code != 1)
        return ERR_INPUT;
    printf("%d\n", countOnes(n));
    return 0;
}

int countOnes(int n)
{
  int ones_counter = 0;
  while (n)
    {
        if (n % 2)
            ++ones_counter;
        n /= 2;
    }
    return ones_counter;
}