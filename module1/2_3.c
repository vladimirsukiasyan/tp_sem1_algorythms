#include <stdio.h>
#define ERR_INPUT -1

void printInBaseM(int n, int m);

int main(void)
{
    int n, m, code = scanf("%d%d", &n, &m);	//n - number; m - base<2-36>
    if (code != 2)
        return ERR_INPUT;
    printInBaseM(n, m);
    putchar('\n');
    return 0;
}

void printInBaseM(int n, int m)
{
    if (n / m)
        printInBaseM(n/m, m);
    if ((n % m) < 10)
        printf("%d", (n % m));
    else
        printf("%c", ('A' + (n % m) - 10));
}
