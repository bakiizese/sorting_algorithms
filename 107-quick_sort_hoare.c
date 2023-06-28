#include "sort.h"
void recurs(int *array, int ft, int lt, size_t size);
/**
 * part - entry
 * @array: var
 * @ft: var
 * @lt: var
 * @size: var
 * Return: j
 */
int part(int *array, int ft, int lt, size_t size)
{
	int pt = array[lt];
	int i = ft - 1;
	int j = lt + 1, x;

	while (1)
	{
		do {
			j--;
		} while (array[j] > pt);

		do {
			i++;
		} while (array[i] < pt);

		if (j < i)
			return (j);
		if (array[i] > array[j])
		{
			x = array[i];
			array[i] = array[j];
			array[j] = x;
			print_array(array, size);
		}
	}
}
/**
 * quick_sort_hoare - entry
 * @array: var
 * @size: var
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	recurs(array, 0, size - 1, size);
}
/**
 * recurs - entry
 * @array: var
 * @ft: var
 * @lt: var
 * @size: var
 */
void recurs(int *array, int ft, int lt, size_t size)
{
	int pt;

	if (ft < lt)
	{
		pt = part(array, ft, lt, size);
		recurs(array, ft, pt, size);
		recurs(array, pt + 1, lt, size);
	}
}
