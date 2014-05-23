#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ERR_INPUT -1
#define ERR_ALLOC -2

void *createStack(int);
void removeStack(void);
void push(int);
int pop(void);
int isEmpty();

int calculate(void);
int main(void)
{
    if (!createStack(128))
        return ERR_ALLOC;
    calculate();
    removeStack();
	return 0;
}

int calculate(void)
{
    int numbuf = 0;
    char head = 0;
    push((int)head);
    char c = 0;
    while (c != '\n')
    {
        c = getchar();
        while(c == ' ')
            c = getchar();
        if (isdigit(c))
        {
            numbuf = 0;
            while (isdigit(c))
            {
                numbuf = numbuf * 10 + atoi(&c);
                c = getchar();
            }
            printf("%d ", numbuf);
        }
        else if (c == '+' || c == '-')
        {
            head = (char)pop();
            if (head == '*' || head == '/')
            {
                while (head == '*' || head == '/')
                {
                    printf("%c ", head);
                    head = (char)pop();
                }
            }
            push((int)head);
            push((int)c);
        }
        else if (c == '*')
        {
            push((int)c);
        }
        else if (c == '/')
        {
            head = (char)pop();
            if (head == '*')
            {
                while (head == '*')
                {
                    printf("%c ", head);
                    head = (char)pop();
                }
                push((int)head);
            }
            push((int)c);
        }
        else if (c == '(')
        {
            push((int)c);
        }
        else if (c == ')')
        {
            head = (char)pop();
            while (head != '(')
            {
                printf("%c ", head);
                head = (char)pop();
            }
        }
    }
    while (!isEmpty())
        printf("%c ", (char)pop());
    return 0;
}

//----------работа со стеком----------//

int *stack;
int size;
int current;

void doubleStack();

void *createStack(int n)
{
	stack = (int *)malloc(n * sizeof(int));
	size = n;
	current = 0;
    return stack;
}

void removeStack(void)
{
    free(stack);
}

void push(int val)
{
	if (current == size)
		doubleStack();
	stack[current++] = val;
}

int pop(void)
{
	if (current == 0)
	{
		printf("Stack is empty");
		return 0;
	}
	return stack[--current];
}

int isEmpty()
{
    return current ? 0 : 1;
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
