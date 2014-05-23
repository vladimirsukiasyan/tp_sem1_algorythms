/*7_1. Жадина.
 *Вовочка ест фрукты из бабушкиной корзины. В корзине лежат фрукты разной массы.
 *Вовочка может поднять не более K грамм. Каждый фрукт весит не более K грамм. 
 *За раз он выбирает несколько самых тяжелых фруктов, которые может поднять одновременно, 
 *откусывает от каждого половину и кладет огрызки обратно в корзину. Если фрукт весит нечетное число *
 *грамм, он откусывает большую половину. Фрукт массы 1гр он съедает полностью.
 *У Вовочки просыпается совесть, если в очередной раз он пытается взять из корзины не меньше половины (по массе) оставшихся фруктов, в этом случае он останавливается.
 *Определить массу оставшихся в корзине фруктов.
*/

#include <stdio.h>

#define ERR_INPUT -1

void Heapify(int *heap, int size, int i);
void BuildHeap(int *heap, int size);

int EatSomeHalfFruits(int *fruits, int n, int maxMass, int fullMass);

int main(void)
{
	int n;
	int code = scanf("%d", &n);
	if (code != 1 || (n < 1))
		return ERR_INPUT;
	int fruits[n];
	int i;
	for (i = 0; i < n; ++i)
	{
		code = scanf("%d", &fruits[i]);
		if (code != 1 || (fruits[i] < 1))
			return ERR_INPUT;
	}

    BuildHeap(fruits, n);

	int maxMass;
	code = scanf("%d", &maxMass);
	if (code != 1 || (maxMass < 1))
		return ERR_INPUT;

	code = 1;
    int estMass;
    estMass = 0;
    for (i = 0; i < n; ++i)
        estMass += fruits[i];
    while (code)
    {
        code = EatSomeHalfFruits(fruits, n, maxMass, estMass);
        if (code)
            estMass = code;
    }
	printf("%d", estMass);
	return 0;
}

void Heapify(int *heap, int size, int i)
{
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int largest = i;
    if ((left < size) && (heap[left] > heap[largest]))
		largest = left;
    if ((right < size) && (heap[right] > heap[largest]))
        largest = right;
	if (largest != i)
	{
		int temp = heap[i];
		heap[i] = heap[largest];
		heap[largest] = temp;
		Heapify(heap, size, largest);
	}
}

void BuildHeap(int *heap, int size)
{
	int i;
	for (i = size / 2 - 1; i >= 0; --i)
		Heapify(heap, size, i);
}

int EatSomeHalfFruits(int *fruits, int n, int maxMass, int fullMass)
{
    int mass = 0, estMass = fullMass;

    while ((mass + fruits[0]) <= maxMass)
    {
        mass += fruits[0];
        if (fruits[0] % 2)
            --estMass;
        fruits[0] /= 2;
        estMass -= fruits[0];
        Heapify(fruits, n, 0);
    }

    if ((mass * 2) >= fullMass)
        return 0;
    return estMass;
}
