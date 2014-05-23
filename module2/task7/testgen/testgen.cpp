#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>

using namespace std;

const int maxSize = 250000;//00000;

int main()
{
    srand(time(0));
    freopen("test0", "w", stdout);
    for (size_t i = 0; i < maxSize; ++i)
        cout << (rand() % maxSize) << " ";
    freopen("test1", "w", stdout);
    for (size_t i = 0; i < maxSize; ++i)
        cout << 1 << " ";
    freopen("test2", "w", stdout);
    for (ssize_t i = maxSize - 1; i >= 0; --i)
        cout << i << " ";
    freopen("test3", "w", stdout);
    for (size_t i = 0; i < maxSize; ++i)
        cout << i % static_cast<int>(sqrt(maxSize)) << " ";
    return 0;
}
