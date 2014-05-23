#include <stdio.h>
#include <stdlib.h>
#define ERR_INPUT -1

double polygonSquare(int *, int *, int);

int main(void)
{
    int n, code = scanf("%d", &n);
    if (code != 1)
    return ERR_INPUT;
    int x[n], y[n];
    int i;
    for (i = 0; i < n; ++i)
    {
    code = scanf("%d", &x[i]);
    if (code != 1)
        return ERR_INPUT;
    code = scanf("%d", &y[i]);
    if (code != 1)
        return ERR_INPUT;
    }
    printf("%.1f\n", polygonSquare(x, y, n));
    return 0;
}

double polygonSquare(int *x, int *y, int n)
{
    double square = 0;
    int i;
    for (i = 0; i < (n - 1); ++i)
        square += (x[i] + x[i + 1]) * (y[i] - y[i + 1]);
    square += (x[n - 1] + x[0]) * (y[n - 1] - y[0]);
    square /= 2.0;
    return (square >= 0) ? square : -square;
}
