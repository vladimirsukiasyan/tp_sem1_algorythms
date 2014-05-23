/*Карбовский Сергей, р. АПО-11
Задание 3_3. Закраска прямой 1.
На числовой прямой окрасили N отрезков. Известны координаты левого и правого концов 
каждого отрезка (Li и Ri). Найти длину окрашенной части числовой прямой.
*/
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int ERRINPUT = -1;

typedef enum {BEGIN, END} pointType;

typedef struct
{
	int value;
	pointType type;
} coordinate;

void mergeSort(vector<coordinate> &coord, int first, int last);

int main()
{
	int n;
	cin >> n;
	if (n <= 0)
		return ERRINPUT;
    vector<coordinate> lines(2 * n);
    for (vector<coordinate>::iterator i = lines.begin(); i != lines.end(); i += 2)
    {
        cin >> (*(i)).value;
        (*(i)).type = BEGIN;
        cin >> (*(i+1)).value;
        (*(i+1)).type = END;
    }
    mergeSort(lines, 0, 2 * n - 1);

	int colourationLevel = 0;
	int colouredLength = 0;
	int current = 0;
	for (int i = 0; i < 2 * n; ++i)
	{
		if (lines[i].type == BEGIN)
			++colourationLevel;
		else --colourationLevel;
		if (colourationLevel == 0)
		{
			colouredLength += (lines[i].value - lines[current].value);
			current = i + 1;
		}
	}
	cout << colouredLength << endl;
	return 0;
}

void swap(coordinate *x, coordinate *y)
{
	coordinate temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void merge(vector<coordinate> &coord, int first, int mid, int last)
{
	int leftSize = mid - first + 1;
	int rightSize = last - (mid + 1) + 1;
	vector<coordinate> left(leftSize + 1), right(rightSize + 1);
	for (int i = 0; i < leftSize; ++i)
		left[i] = coord[first + i];
	for (int i = 0; i < rightSize; ++i)
		right[i] = coord[mid + 1 + i];
	left[leftSize].value = right[rightSize].value = INT_MAX;
	for (int i = 0, j = 0, k = first; k <= last; ++k)
	{
		if (left[i].value == right[j].value)
		{
			if ((left[i].type == BEGIN) && (right[j].type == END))
				coord[k] = left[i++];
			else if ((left[i].type == END) && (right[j].type == BEGIN))
				coord[k] = right[j++];
			else
				coord[k] = left[i++];
		}
		else
		{
			if (left[i].value < right[j].value)
				coord[k] = left[i++];
			else
				coord[k] = right[j++];
		}
	}
}

void mergeSort(vector<coordinate> &coord, int first, int last)
{
	if (first < last)
	{
		if (last - first == 1)
		{
			if (coord[last].value < coord[first].value)
			{
				swap(coord[first], coord[last]);
				return;
			}
			
			if ((coord[last].value == coord[first].value) &&
				(coord[last].type == BEGIN) &&
				(coord[first].type == END))
			{
				swap(coord[first], coord[last]);
				return;
			}
		}
		else 
		{
			int mid = (first + last) / 2;
			mergeSort(coord, first, mid);
			mergeSort(coord, mid + 1, last);
			merge(coord, first, mid, last);
		}
	}
}
