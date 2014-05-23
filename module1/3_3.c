#include <stdio.h>
#include <stdlib.h>
#define ERR_INPUT -1

int numOfIntersection(int *a, int n, int *b, int m);

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

    printf("%d\n", numOfIntersection(a, n, b, m));
    return 0;
}

int numOfIntersection(int *a, int n, int *b, int m)
{
    int i = 0, j = 0;
    int equals = 0;
    while (i < n && j < m)
    {
        if (a[i] < b[j])
            ++i;
        else if(a[i] > b[j])
            ++j;
        else
        {
            //printf("%d ", a[i]);
            ++equals;
            ++i;
            ++j;
        }
    }
    return equals;
}
