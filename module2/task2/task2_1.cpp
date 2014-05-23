/*Карбовский Сергей, р. АПО-11
Задание 2_1. Ящики.
На склад привезли много пустых ящиков. Все ящики пронумерованы по порядку поступления от 0.
Известно, что их все можно сложить один в один (то есть так, что каждый следующий помещается в
предыдущий). Один ящик можно вложить в другой, если его можно перевернуть так, что размеры одного
ящика по всем осям станут строго меньше размеров другого ящика по соответствующим осям. Требуется
определить, в какой последовательности они будут вложены друг в друга. Вывести номера ящиков.
*/

#include <iostream>
#include <vector>

const int ERRINPUT = -1;

class Box
{
private:
    int x;
    int y;
    int z;
    int index;
public:
    Box(int x, int y, int z, int index): x(x), y(y), z(z), index(index)
    {
        if (this->x > this->y)
            std::swap(this->x, this->y);
        if (this->x > this->z)
            std::swap(this->x, this->z);
        if (this->y > this->z)
            std::swap(this->y, this->z);
    }
    bool operator>(Box& op2)
    {
        if ((x > op2.x) && (y > op2.y) && (z > op2.z))
            return true;
        else
            return false;
    }
    inline int getIndex()
    {
        return index;
    }
};

template<class Iterator>
void HeapSort(Iterator begin, Iterator end);

int main(void)
{
    int size;
    std::cin >> size;
    if (!std::cin.good())
        return ERRINPUT;
    std::vector<Box> boxes;
    int bufX, bufY, bufZ;
    int i;
    for (i = 0; i < size; ++i)
    {
        std::cin >> bufX >> bufY >> bufZ;
        if (!std::cin.good())
            return ERRINPUT;
        boxes.push_back(Box(bufX, bufY, bufZ, i));
    }
    HeapSort(boxes.begin(), boxes.end());

    for (i = 0; i < size; std::cout << boxes[i++].getIndex() << " ");
    std::cout << std::endl;
}

template<class Iterator>
void Heapify(Iterator begin, Iterator end, Iterator i)
{
    bool isHeapified = false;
    do
    {
        Iterator left = i + std::distance(begin, i) + 1;
        Iterator right = i + std::distance(begin, i) + 2;
        Iterator largest = i;
        if ((left < end) && (*left > *largest))
            largest = left;
        if ((right < end) && (*right > *largest))
                largest = right;
        if (largest != i)
        {
            std::swap(*i, *largest);
            i = largest;
        }
        else
            isHeapified = true;
    }
    while (!isHeapified);
}

template<class Iterator>
void HeapSort(Iterator begin, Iterator end)
{
    //Построение бинарной пирамиды
    for (Iterator i = begin + std::distance(begin, end) / 2; i >= begin; --i)
        Heapify(begin, end, i);
    //Сортировка
    for (Iterator i = end - 1; i >= begin; --i)
    {
        std::swap(*begin, *i);
        Heapify(begin, i, begin);
    }
}
