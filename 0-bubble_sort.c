#include "sort.h"
#include <stdio.h>
/**
 * bubble_sort - entry
 * @array: array
 * @size: var
 */
void bubble_sort(int *array, size_t size)
{
	size_t n, t;
	int h;

	if (array == NULL)
		return;

	for (t = 0; t < size; t++)
	{
		for (n = 0; n < size - 1; n++)
		{
			if (array[n] > array[n + 1])
			{
				h = array[n];
				array[n] = array[n + 1];
				array[n + 1] = h;
				print_array(array, size);
			}
		}
	}
}
