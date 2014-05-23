#include <stdio.h>
#define ERR_INPUT -1

int numOfSums(int *a, int n, int *b, int m, int k);

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
        if (code != 1)
            return ERR_INPUT;
    }

    int m;
    code = scanf("%d", &m);
    if (code != 1)
        return ERR_INPUT;
    int b[m];
    for (i = 0; i < m; ++i)
    {
        code = scanf("%d", &b[i]);
        if (code != 1)
            return ERR_INPUT;
    }
    int k;
    code = scanf("%d", &k);
    if (code != 1)
        return ERR_INPUT;

    printf("%d\n", numOfSums(a, n, b, m, k));
    return 0;
}

int numOfSums(int *a, int n, int *b, int m, int k)
{
    int i = 0, j = m - 1;
    int equalsK = 0;
    while (i < n && j >= 0)
    {
        if ((a[i] + b[j]) < k)
            ++i;
        else if ((a[i] + b[j]) > k)
            --j;
        else
        {
            ++equalsK;
            ++i;
            --j;
        }
    }
    return equalsK;
}
