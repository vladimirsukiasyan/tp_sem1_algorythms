/*Карбовский Сергей, гр. АПО-11
Задание 5_2. Почти отсортированная последовательность
Дана последовательность целых чисел a1...an и натуральное число k, такое что
для любых i, j: если j >= i + k, то a[i] <= a[j]. Требуется отсортировать
последовательность. Последовательность может быть очень длинной.
Время работы O(n * log(k)). Доп. память O(k). Использовать слияние.
*/
#include <iostream>
#include <vector>

const int ERRINPUT = -1;

template<class Iterator>
void mergeSort(Iterator begin, Iterator end);

int main(void)
{
    size_t n, k;
    std::cin >> n >> k;
    if (!std::cin.good())
        return ERRINPUT;

    std::vector<int> a(1);

    std::cin >> a[0];
    if (!std::cin.good())
        return ERRINPUT;
    size_t i = 0;
    do
    {
        ++i;
        size_t buf = 0;
        std::cin >> buf;
        if (!std::cin.good())
            return ERRINPUT;
        a.push_back(buf);
    } while (a[i] <= a[i - 1]);
    ++i;

    int temp = *(a.end() - 1);
    a.erase(a.end() - 1);
    mergeSort(a.begin(), a.end());
    for (std::vector<int>::iterator iter = a.begin(); iter != a.end(); ++iter)
        std::cout << *iter << " ";
    a.clear();
    a.push_back(temp);

    while (i < n)
    {
        for (size_t j = a.size(), buf = 0; (j < k) && (i < n); ++j, ++i)
        {
            std::cin >> buf;
            if (!std::cin.good())
                return ERRINPUT;
            a.push_back(buf);
        }
        mergeSort(a.begin(), a.end());
        for (std::vector<int>::iterator iter = a.begin(); iter != a.end(); ++iter)
            std::cout << *iter << " ";
        a.clear();
    }
    std::cout << std::endl;
	return 0;
}

template<class Iterator>
void mergeSort(Iterator begin, Iterator end)
{
    if (std::distance(begin, end) <= 1)
        return;
    if (std::distance(begin, end) == 2)
    {
        if (*begin > *(end - 1))
            std::swap(*begin, *(end - 1));
        return;
    }
    Iterator middle = begin + std::distance(begin, end) / 2;
    mergeSort(begin, middle);
    mergeSort(middle, end);

    size_t bufSizeA = std::distance(begin, middle);
    size_t bufSizeB = std::distance(middle, end);

    std::vector<int> bufferA(bufSizeA), bufferB(bufSizeB);

    for (Iterator i = bufferA.begin(), j = begin; i != bufferA.end(); ++i, ++j)
        *i = *j;
    for (Iterator i = bufferB.begin(), j = middle; i != bufferB.end(); ++i, ++j)
        *i = *j;

    Iterator i = bufferA.begin(), j = bufferB.begin(), k = begin;
    while ((i != bufferA.end()) && (j != bufferB.end()))
    {
        if (*i <= *j)
            *(k++) = *(i++);
        else
            *(k++) = *(j++);
    }
    while (i != bufferA.end())
        *(k++) = *(i++);
    while (j != bufferB.end())
        *(k++) = *(j++);
}
