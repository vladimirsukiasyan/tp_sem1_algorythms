#include <stdio.h>
#define ERR_INPUT -1

int missed(int *, int);

int main(void)
{
    int n;
    int code = scanf("%d", &n);
    if (code != 1)
        return ERR_INPUT;
    int a[n];
    int i;
    for (i = 0; i < n; ++i)
    {
        code = scanf("%d", &a[i]);
        if ((code != 1) || (a[i] > n))
            return ERR_INPUT;
    }

    printf("%d\n", missed(a, n));
    return 0;
}

int missed(int *a, int n)
{
    int sum =  n * (n + 1) / 2;
    while(n)
        sum -= a[--n];
    return sum;
}
