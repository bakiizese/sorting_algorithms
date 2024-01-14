#include "sort.h"
int gmax(int *array, int size);
void rcounting_sort(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);
/**
 * gmax - intery
 * @array: var
 * @size: var
 * Return: max
 */
int gmax(int *array, int size)
{
	int mx, i;

	for (mx = array[0], i = 1; i < size; i++)
	{
		if (array[i] > mx)
			mx = array[i];
	}

	return (mx);
}

/**
 * rcounting_sort - entry
 * @array: var
 * @size: var
 * @sig: var
 * @buff: bf
 **/
void rcounting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - entry
 * @array: var
 * @size: var
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = gmax(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		rcounting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}

