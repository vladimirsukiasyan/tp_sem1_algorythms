/* Дан массив целых чисел A[0..n). Для каждого участка из m стоящих рядом членов
 * вычислить сумму элементов. Общее число действий O(n). На вход вначале поступает
 * массив, а затем число m.
 */

#include <stdio.h>
#include <stdlib.h>
#define ERR_INPUT -1

void printSumOfAll_M_ElementsInArray(int *, int,  int);

int main(void)
{
    int size, code = scanf("%d", &size);
    if (code != 1)
        return ERR_INPUT;
    int ar[size];

    int i;
    for (i = 0; i < size; ++i)
    {
        code = scanf("%d", &ar[i]);
        if (code != 1)
            return ERR_INPUT;
    }

    int m;
    code = scanf("%d", &m);
        if (code != 1)
            return ERR_INPUT;

    printSumOfAll_M_ElementsInArray(ar, size, m);
    return 0;
}

void printSumOfAll_M_ElementsInArray(int *ar, int size, int m)
{
    int i;
    int sumsSize = size - m;
    int tempSum = 0;

    for (i = 0; i < m; ++i)
        tempSum += ar[i];
    printf("%d ", tempSum);

    for (i = 0; i < sumsSize; ++i)
    {
        tempSum -= ar[i];
        tempSum += ar[m + i];
        printf("%d ", tempSum);
    }
    putchar('\n');
}
