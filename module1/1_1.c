#include <stdio.h>

int countLuckyTickets(void);

int main(void)
{
  printf("%d\n", countLuckyTickets());
  return 0;
}

int countLuckyTickets(void)
{
  int i, j, lucky_tickets_counter = 0;
  int leftsum, rightsum, buf;
  for (i = 0; i < 1000000; ++i)
  {
    leftsum = rightsum = 0;
    buf = i;
    for (j = 0; j < 3; ++j)
    {
      leftsum += buf % 10;
      buf /= 10;
    }
    for (j = 0; j < 3; ++j)
    {
      rightsum += buf % 10;
      buf /= 10;
    }
    if (leftsum == rightsum)
      ++lucky_tickets_counter;
  }
  return lucky_tickets_counter;
}