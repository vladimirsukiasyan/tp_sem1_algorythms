/*
 * Карбовский Сергей, гр. АПО - 11
 * Задание 6_1. MSD для строк.
 * Дан массив строк. Количество строк не больше 10^5.
 * Отсортировать массив методом поразрядной сортировки MSD по символам.
 * Размер алфавита - 256 символов. Последний символ строки = ‘\0’
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

typedef std::vector<std::string> strings;

void radix_msd_sort(strings::iterator begin, strings::iterator end, size_t offset);

int main()
{
    std::string buffer;
    strings words;
    std::cin >> buffer;
    while (!std::cin.eof())
    {
        if (!buffer.empty())
        {
            words.push_back(buffer);
        }
        buffer.clear();
        std::cin >> buffer;
    }

    radix_msd_sort(words.begin(), words.end(), 0);
    for (strings::iterator i = words.begin(); i != words.end(); ++i)
        std::cout << *i << std::endl;
    return 0;
}

void radix_msd_sort(strings::iterator begin, strings::iterator end, size_t offset)
{
    const size_t alphabetSize = 256;

    std::vector<strings> buckets(alphabetSize);
    for (strings::iterator i = begin; i != end; ++i)
        buckets[static_cast<size_t>((*i)[offset])].push_back(*i);
    for (size_t i = 1; i < alphabetSize; ++i)
    {
        if (buckets[i].size() > 1)
            radix_msd_sort(buckets[i].begin(), buckets[i].end(), offset + 1);
    }
    size_t k = 0;
    for (strings::iterator i = begin; i != end;)
    {
        for (strings::iterator j = buckets[k].begin(); j != buckets[k].end(); ++j)
            *i++ = *j;
        ++k;
    }

}
