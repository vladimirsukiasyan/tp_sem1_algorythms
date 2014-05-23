#include <stdio.h>
#include <stdlib.h>
#define ERR_INPUT -1
#define ERR_ALLOC -2

void printArraysIntersection(int *, int *, int, int);
int binarySearch(int, int *, int, int);

int main()
{
	int n, m, i;
	int code = scanf("%d%d", &n, &m);
	if (code != 2)
		return ERR_INPUT;

	int *a = (int *)malloc(n * sizeof(int));
	if (!a)
		return ERR_ALLOC;

	int *b = (int *)malloc(m * sizeof(int));
		if (!b)
		return ERR_ALLOC;

	for (i = 0; i < n; ++i)
	{
		int code = scanf("%d", &a[i]);
		if (code != 1)
		{
			free(a);
			free(b);
			return ERR_INPUT;
		}
	}
	for (i = 0; i < m; ++i)
	{
		int code = scanf("%d", &b[i]);
		if (code != 1)
		{
			free(a);
			free(b);		
			return ERR_INPUT;
		}
	}
	printArraysIntersection(a, b, n, m);

	return 0;
}

void printArraysIntersection(int *a, int *b, int n, int m)
{
	int i;
	for (i = 0; i < m; ++i)
	{
		if (binarySearch(b[i], a, 0, n) != -1)
			printf("%d ", b[i]);
	}
}

int binarySearch(int element, int *array, int start, int finish)
{
	int pos = (start + finish) / 2;
	if (start > finish)
		return -1;
	if (element == array[pos])
		return pos;
	else if (element < array[pos])
		return binarySearch(element, array, start, pos - 1);
	else
		return binarySearch(element, array, pos + 1, finish);
}