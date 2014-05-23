/*
Карбовский Сергей, гр. АПО-11
Задача 1_3
Реализовать алгоритм сортировки пузырьком массива целых чисел.
Количество чисел в массиве определяется окончанием стандартного потока ввода и заранее не известно.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERRINPUT -1
#define STARTSIZE 16

void bubbleSort(int *array, int size);

int main(void)
{

	int bufSize = STARTSIZE;
	int *array = (int *)calloc(bufSize, sizeof(int));
	int *temp_alloc = NULL;
	int arraySize = 0, j = 0;
	int elem;
	int code = scanf("%d", &elem);
	if (code != 1)
	{
		free(array);
		return ERRINPUT;
	}
	while (1)
	{
		array[arraySize++] = elem;
		if (arraySize == bufSize)
		{
			temp_alloc = (int *)calloc(bufSize * 2, sizeof(int));
			temp_alloc = (int *)memcpy(temp_alloc, array, bufSize * sizeof(int));
			bufSize *= 2;
			free(array);
			array = temp_alloc;
			temp_alloc = NULL;
		}
		code = scanf("%d", &elem);
		if (code == EOF)
			break;
		else if (code != 1)
		{
			free(array);
			printf("%d\n", elem);
			return ERRINPUT;
		}
	}

	bubbleSort(array, arraySize);

	for (j = 0; j < arraySize; ++j)
		printf("%d ", array[j]);
	free(array);
	return 0;
}

void bubbleSort(int *array, int size)
{
	int i, temp, swaps;
	do
	{
		swaps = 0;
		for (i = 1; i < size; ++i)
			if (array[i - 1] > array[i])
			{
				temp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = temp;
				++swaps;
			}
	}
	while (swaps);
}
