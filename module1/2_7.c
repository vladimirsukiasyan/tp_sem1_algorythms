#include <stdio.h>
#include <stdlib.h>
#define ERR_INPUT -1

void arrayReverse(int *, int, int);

int main(void)
{
  int *ar, size, code = scanf("%d", &size);
  if (code != 1)
    return ERR_INPUT;
  ar = malloc(size * sizeof(int));
  
  int i;
  for (i = 0; i < size; ++i)
  {
      code = scanf("%d", &ar[i]);
  if (code != 1)
    return ERR_INPUT;  
  }

  arrayReverse(ar, 0, size - 1);
  
  for (i = 0; i < size; ++i)
    printf("%d ", ar[i]);
  putchar('\n');
  
  free(ar);
  return 0;
}

void arrayReverse(int *ar, int start, int stop)
{
  int buf;
  buf = *(ar + start);
  *(ar + start) = *(ar + stop);
  *(ar + stop) = buf;
    
  if (++start < --stop)
    arrayReverse(ar, start, stop);
}
