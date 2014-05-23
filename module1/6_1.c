#include <stdio.h>
#include <stdlib.h>

#define ERR_INPUT -1

void createStack(int);
void push(int);
int pop();

int main(void)
{
	int n = 0, code = scanf("%d", &n);
	if (code != 1)
		return ERR_INPUT;
	int *stack = createStack(n);

	free(stack);
	return 0;
}

//----------работа со стеком----------//

int *stack;
int size;
int current;

void doubleStack();

int *createStack(int n)
{
	stack = (int *)malloc(n * sizeof(int));
	size = n;
	current = 0;
	return stack;
}

void push(int val)
{
	if (current == size)
		doubleStack();
	stack[current++] = val;
}

int pop()
{
	if (current == 0)
	{
		printf("Stack is empty");
		return 0;
	}
	return stack[--current];
}

void doubleStack()
{
	int *temp = (int *)malloc(2 * size * sizeof(int));
	int i;
	for (i = 0; i < size; ++i)
		temp[i] = stack[i];
	size *= 2;
	free(stack);
	stack = temp;
}