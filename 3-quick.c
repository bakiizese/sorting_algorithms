#include "sort.h"
/**
 * part - entry partition
 * @array: array
 * @bg: var
 * @fn: var
 * @size: var
 * Return: k + 1
 */
int part(int *array, int bg, int fn, size_t size)
{
	int k = bg - 1;
	int hol, j;

	for (j = bg; j <= fn - 1; j++)
	{
		if (array[j] < array[fn])
		{
			k++;
			if (k < j)
			{
				hol = array[k];
				array[k] = array[j];
				array[j] = hol;
				print_array(array, size);
			}
		}
	}
	if (array[k + 1] > array[fn])
	{
		hol = array[k + 1];
		array[k + 1] = array[fn];
		array[fn] = hol;
		print_array(array, size);
	}
	return (k + 1);
}
/**
 * recurse - entry
 * @array: array
 * @bg: var
 * @fn: var
 * @size: var
 */
void recurse(int *array, int bg, int fn, size_t size)
{
	int piv;

	if (bg < fn)
	{
		piv = part(array, bg, fn, size);
		recurse(array, bg, piv - 1, size);
		recurse(array, piv + 1, fn, size);
	}
}
/**
 * quick_sort - entry
 * @array: array
 * @size: var
 */
void quick_sort(int *array, size_t size)
{
	recurse(array, 0, size - 1, size);
}
