#include "sort.h"
/**
 * shell_sort - entry
 * @array: var
 * @size: var
 */
void shell_sort(int *array, size_t size)
{
	int g = 1;
	int i, j, k;

	while (g < ((int)(size)))
		g = (3 * g) + 1;
	for (g = (g - 1) / 3; g > 0; g = (g - 1) / 3)
	{
		for (i = g; i < (int)size; i++)
		{
			k = array[i];
			for (j = i; j >= g && array[j - g] > k; j -= g)
				array[j] = array[j - g];
			array[j] = k;
		}
		print_array(array, size);
	}
}
