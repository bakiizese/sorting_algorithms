#include "sort.h"
/**
 * selection_sort - entry
 * @array: array
 * @size: var
 */
void selection_sort(int *array, size_t size)
{
	size_t ls, i, c, h, sw;

	if (array == NULL)
		return;

	for (i = 0; i < size; i++)
	{
		for (ls = i, c = i; c < size; c++)
		{
			if (array[c] < array[ls])
			{
				ls = c;
				sw = 1;
			}
		if (sw == 1)
		{
			h = array[ls];
			array[ls] = array[i];
			array[i] = h;
			print_array(array, size);
			sw = 0;
		}
		}
	}
}
