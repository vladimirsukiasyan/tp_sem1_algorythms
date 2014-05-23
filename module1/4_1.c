#include <stdio.h>
#include <stdlib.h>
#define ERR_INPUT -1
#define ERR_ALLOC -2

void findMinGreaser(int *, int *, int, int);
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

	findMinGreaser(a, b, n, m);

	return 0;
}

void findMinGreaser(int *a, int *b, int n, int m)
{
	int i;
	int start, finish, mid;
	int elem;
	for (i = 0; i < m; ++i)
	{
		start = 0;
		finish = n - 1;
		elem = b[i];
		while (start < finish)
		{
			mid = (start + finish) / 2;
			if (elem >= a[finish])
				printf("%d ", finish);
			else if (elem == a[mid])
				printf("%d ", mid);
			else if (elem < a[mid])
				finish = mid - 1;
			else
				start = mid + 1;			
		}
	}
}
