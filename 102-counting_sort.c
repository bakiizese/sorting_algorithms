#include "sort.h"
/**
 * maxs - entry
 * @array: var
 * @size: var
 * Return: max
 */
int maxs(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}
/**
 * counting_sort - entry
 * @array: var
 * @size: var
 */
void counting_sort(int *array, size_t size)
{
	int max, num, *narr, *sarr;
	size_t i;

	if (!array || size < 2)
		return;

	max = maxs(array, size);
	sarr = malloc(sizeof(int) * size);
	narr = malloc(sizeof(size_t) * (max + 1));

	for (i = 0; (int)i <= max; i++)
		narr[i] = 0;
	for (i = 0; i < size; i++)
	{
		num = array[i];
		narr[num] += 1;
	}
	for (i = 0; (int)i <= max; i++)
	{
		narr[i] += narr[i - 1];
	}
	print_array(narr, max + 1);
	for (i = 0; i < size; i++)
	{
		sarr[narr[array[i]] - 1] = array[i];
		narr[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = sarr[i];

	free(narr);
	free(sarr);
}
