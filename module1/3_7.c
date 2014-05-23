#include <stdio.h>
#define ERR_INPUT -1

int lastInCircle(int, int);

int main(void)
{
    int n, k;
    int code = scanf("%d%d", &n, &k);
    if (code != 2)
        return ERR_INPUT;
    printf("%d\n", lastInCircle(n, k));
    return 0;
}

int lastInCircle(int n, int k)
{
    int isAlive[n + 1];
    int i, estimatedOffset, alive;

    isAlive[0] = 0;
    for (i = 0; i <= n; ++i)
        isAlive[i] = 1;
    alive = n;
    i = 0;
    while (alive >= 1)
    {
        estimatedOffset = k;
        while (estimatedOffset)
        {
            ++i;
            if (i > n)
                i -= n;
            if (isAlive[i])
                --estimatedOffset;
        }
        isAlive[i] = 0;
        --alive;
    }
    return i;
}
