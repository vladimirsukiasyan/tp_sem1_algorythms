#include <stdio.h>
#define ERR_INPUT -1

int maxDivSum(int); //returns lower number of sum

int main(void)
{
    int a, n, code = scanf("%d", &n);
    if (code != 1)
        return ERR_INPUT;
    a = maxDivSum(n);
    printf("%d %d\n", a, n - a);
    return 0;
}

int maxDivSum(int n)
{
    int i = n / 2;
    while (n % i)
        --i;
    return i;
}
