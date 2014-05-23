/*
Карбовский Сергей, гр. АПО-11
Задание 4_2. Порядковые статистики.
Реализуйте стратегию выбора опорного элемента “медиана трёх”.
Функцию Partition реализуйте методом прохода двумя итераторами от конца массива к началу.
*/
#include <iostream>
#include <vector>

const int ERRINPUT = -1;

template<class Iterator>
void order_statistics(Iterator begin, Iterator end, size_t k);

int main()
{
    size_t n, k;
    std::cin >> n >> k;
    if (!std::cin.good())
        return ERRINPUT;

    std::vector<int> a(n);
    for (std::vector<int>::iterator iter = a.begin(); iter != a.end(); ++iter)
    {
        std::cin >> *iter;
        if (!std::cin.good())
            return ERRINPUT;
    }

    order_statistics(a.begin(), a.end(), k);

    std::cout << a[k] << std::endl;
    return 0;
}

template<class Iterator>
Iterator choosePivot(Iterator begin, Iterator end)
{
    Iterator first = begin,
             middle = begin + std::distance(begin, end) / 2,
             last = end - 1;
    if (*first > *middle)
        std::swap(first, middle);
    if (*first > *last)
        std::swap(first, last);
    if (*middle > *last)
        std::swap(middle, last);
    return middle;
}

template<class Iterator>
Iterator partition(Iterator begin, Iterator end)
{
    Iterator pivot = choosePivot(begin, end);
    std::swap(*begin, *pivot);
    pivot = begin;

    Iterator i, j;
    for (i = j = end - 1; j != pivot; --j)
    {
        if (*j > *pivot)
        {
            std::swap(*i, *j);
            --i;
        }
    }
    std::swap(*pivot, *i);
    return i;
}

template<class Iterator>
void order_statistics(Iterator begin, Iterator end, size_t k)
{
    size_t dist = std::distance(begin, end) + 1;
    Iterator first = begin, last = end;

    while (dist != k)
    {
        Iterator mid = partition(first, last);
        dist = std::distance(begin, mid);
        if (dist < k)
            first = mid;
        else if (dist > k)
            last = mid;
    }
}
