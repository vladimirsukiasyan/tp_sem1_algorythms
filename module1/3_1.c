#include <stdio.h>
#define ERR_INPUT -1

void printMaxSum(int *a, int *b, int n);

int main(void)
{
    int n;
    int code = scanf("%d", &n);
    if (code != 1)
        return ERR_INPUT;

    int a[n], b[n];
    int i;
    for (i = 0; i < n; ++ i)
    {
        code = scanf("%d", &a[i]);
        if (code != 1)
            return ERR_INPUT;
    }
    for (i = 0; i < n; ++ i)
    {
        code = scanf("%d", &b[i]);
        if (code != 1)
            return ERR_INPUT;
    }
    printMaxSum(a, b, n);
    return 0;
}

void printMaxSum(int *a, int *b, int n)
{
    int max, i0, i1, j0, j1;
    int i;
    for (i = i0 = 0, max = a[0]; i < n; ++i)
        if (a[i] > max)
            max = a[i0 = i];

    for (i = j0 = i0, max = b[i0]; i < n; ++i)
        if (b[i] > max)
            max = b[j0 = i];

    for (i = j1 = 0, max = b[0]; i < n; ++i)
        if (b[i] > max)
            max = b[j1 = i];

    for (i = i1 = 0, max = a[0]; i <= j1; ++i)
        if (a[i] > max)
            max = a[i1 = i];
    
    if ((a[i0] + b[j0]) > (a[i1] + b[j1]))
        printf("%d %d\n", i0, j0);
    else
        printf("%d %d\n", i1, j1);

    /*
    int i = 0, j = 0, i0 = 0, j0 = 0;

    while ((i < n) || (j < n))
    {
        if (i0 <= j0) 
        {
        if (a[i] > a[i0])
        {
                i0 = i++;
                j0 = j++;
        }
        else if ((b[j] > b[j0]))
            j0 = j++;
        }
        else
            j++;
    }
    printf("%d %d\n", i0, j0);



    /*
    int i, max;
    int i00 = 0, i01 = 0, j00 = 0, j01 = 0;
    
    //максимальный элемент в массиве a
    max = a[0];    
    for (i = 1; i < n; ++i)
    if (a[i] > max)
    {
        max = a[i];
        i00 = i;
    }
    
    //максимальный элемент в массиве b
    max = b[0];
    for (i = 1; i < n; ++i)
    if (b[i] > max)
    {
        max = b[i];
        j00 = i;
    }
	
    //максимальный элемент в массиве a, индекс которого не превосходит j00
    max = a[0];    
    for (i = 1; i <= j00; ++i)
	if (a[i] > max)
	{
	    max = a[i];
	    i01 = i;
	}

    //максимальный элемент в массиве b, индекс которого не менее i00
    max = b[i00];
    for (i = i00 + 1; i < n; ++i)
	if (b[i] > max)
	{
	    max = b[i];
	    j01 = i;
	}

    if ((a[i00] + b[j01]) >= (a[i01] + b[j00]))
        printf("%d %d\n", i00, j01);
    else
        printf("%d %d\n", i01, j00);
        */
}
