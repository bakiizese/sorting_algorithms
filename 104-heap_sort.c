#include "sort.h"

/**
 * swap - entry
 * @array: var
 * @rt: var
 * @rh: var
 * @size: var
 * Return: nun
 */
void swap(int *array, size_t rt, size_t rh, size_t size)
{
	size_t lt = 0, md = 0, mp = 0, x = 0;

	while ((lt = (2 * rt + 1)) <= rh)
	{
		mp = rt;
		md = lt + 1;
		if (array[mp] < array[lt])
			mp = lt;
		if (md <= rh && array[mp] < array[md])
			mp = md;
		if (mp == rt)
			return;
		x = array[rt];
		array[rt] = array[mp];
		array[mp] = x;
		print_array(array, size);
		rt = mp;
	}
}

/**
 * heap_sort - entry algo
 * @array: var
 * @size: var
 */
void heap_sort(int *array, size_t size)
{
	size_t rh = 0, gap = 0;
	int mp = 0;

	if (array == NULL || size < 2)
		return;

	for (gap = (size - 2) / 2; 1; gap--)
	{
		swap(array, gap, size - 1, size);
		if (gap == 0)
			break;
	}
	rh = size - 1;
	while (hi > 0)
	{
		mp = array[rh];
		array[rh] = array[0];
		array[0] = mp;
		print_array(array, size);
		rh--;
		swap(array, 0, rh, size);
	}
}
