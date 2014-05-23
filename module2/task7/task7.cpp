#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

/*template<class Iterator>
void theQuickestSort(Iterator begin, Iterator end);


int main()
{
    //FILE *input = freopen("test0", "r", stdin);

    const int ERRINPUT = -1;
    std::vector<int> values;
    size_t buffer;
    ssize_t code = 0;
    while(code != EOF)
    {
        code = std::scanf("%d", &buffer);
        if (code != 1 && code != EOF)
            return ERRINPUT;
        values.push_back(buffer);
    }

    //clock_t time0 = std::clock();
    std::sort(values.begin(), values.end());
    //theQuickestSort(values.begin(), values.end());
    //clock_t time1 = std::clock();

    for (std::vector<int>::iterator i = values.begin() +10; i < values.end(); i += 10)
        std::printf("%d ", *i);
    std::printf("\n");

    //std::printf("\n%d\n", static_cast<int>(time1 - time0));
    //fclose(input);
    return 0;
}

template<class Iterator>
void theQuickestSort(Iterator begin, Iterator end)
{
    const size_t nonRecSize = 30;
    size_t size = std::distance(begin, end);

    if (size <= 1)
        return;

    if (size <= nonRecSize)
    {
        for (Iterator i = begin; i != end; ++i)
        {
            Iterator j = i;
            while (j != begin && *(j - 1) > *j)
            {
                std::swap(*(j - 1), *j);
                --j;
            }
        }
        return;
    }

    Iterator left = begin , right = end - 1;
    Iterator pivot = begin + random() % (std::distance(begin, end) / 2 - 1);
    if (*left > *pivot)
        std::swap(*left, *pivot);
    if (*left > *right)
        std::swap(*left, *right);
    if (*pivot > *right)
        std::swap(*pivot, *right);

    bool pivotIsLeft = true;
    std::swap(*begin, *pivot);

    for (left = begin, right = end - 1; left != right;)
    {
        if (*right < *left)
        {
            std::swap(*left, *right);
            pivotIsLeft = !pivotIsLeft;
        }
        if (pivotIsLeft)
            ++left;
        else
            --right;
    }
    theQuickestSort(begin, left);
    theQuickestSort(right, end);
}
*/

int main()
{
    std::vector<int> a;
    size_t buffer;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    size_t i = 0;
    std::cin >> buffer;
    while(!std::cin.eof())
    {
        a.push_back(buffer);
        std::cin >> buffer;
    }
    std::sort(a.begin(), a.end());

    for (std::vector<int>::iterator it = a.begin() + 9; it < a.end(); i += 10)
        std::cout << *it << " ";
    std::cout << std::endl;
    return 0;
}
