#include "sort.h"
int partition(int *array, int low, int high, size_t size);
/**
 * swap - entyr
 * @x: var
 * @y: var
 */
void swap(int *x, int *y)
{
	int tm = *x;
	*x = *y;
	*y = tm;
}
/**
 * recurse - entry
 * @array: var
 * @low: var
 * @high: var
 * @size: var
 */
void recurse(int *array, int low, int high, size_t size)
{
	int piv_point;

	if (low < high)
	{
		piv_point = partition(array, low, high, size);
		recurse(array, low, piv_point - 1, size);
		recurse(array, piv_point + 1, high, size);
	}
}
/**
 * quick_sort - entyr
 * @array: var
 * @size: var
 */
void quick_sort(int *array, size_t size)
{
	recurse(array, 0, size - 1, size);
}
/**
 * partition - entyr
 * @low: var
 * @high: var
 * @size: var
 * @array: var
 * Return: i + 1
 */
int partition(int *array, int low, int high, size_t size)
{
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < array[high])
		{
			i++;
			if (i < j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}
