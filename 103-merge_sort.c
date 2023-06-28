#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_left_right - print left and right partitions
 * @array: array
 * @size: size of second array
 * @first: initial position
 * @mid: middle position
 */
void print_left_right(int *array, int size, int first, int mid)
{
	int k;

	printf("Merging...\n");
	printf("[left]: ");
	k = first;
	while (k < mid)
	{
		if (k != mid - 1)
			printf("%d, ", array[k]);
		else
			printf("%d\n", array[k]);
		k++;
	}

	printf("[right]: ");
	k = mid;
	while (k < size)
	{
		if (k < size - 1)
			printf("%d, ", array[k]);
		else
			printf("%d\n", array[k]);
		k++;
	}
}

/**
 * merge - position of array
 * @array: var
 * @size: var
 * @cpy: var
 * @fs: initial position
 * @md: var
 */
void merge(int *array, int size, int fs, int md, int *cpy)
{
	int i, j, k;

	print_left_right(array, size, fs, md);

	i = fs;
	j = md;

	printf("[Done]: ");
	for (k = fs; k < size; k++)
	{
		if (i < md && (j >= size || array[i] <= array[j]))
		{
			cpy[k] = array[i];
			i++;
		}
		else
		{
			cpy[k] = array[j];
			j++;
		}
		if (k < size - 1)
			printf("%d, ", cpy[k]);
		else
			printf("%d\n", cpy[k]);
	}
}
/**
 * mergesort - array separator
 * @cpy: var
 * @fs: var
 * @size: var
 * @array: var
 */
void mergesort(int *cpy, int fs, int size, int *array)
{
	int md;

	if (size - fs < 2)
		return;

	md = (size + fs) / 2;

	mergesort(array, fs, md, cpy);
	mergesort(array, md, size, cpy);

	merge(cpy, size, fs, md, array);
}
/**
 * cp_array - entry
 * @arr: var
 * @cpy: var
 * @size : var
 */
void cp_array(int *arr, int *cpy, int size)
{
	int i = 0;

	while (i < (int)size)
	{
		cpy[i] = arr[i];
		i++;
	}
}
/**
 * merge_sort - create partition and copy
 * @array: var
 * @size : var
 */
void merge_sort(int *array, size_t size)
{
	int *cpy;

	cpy = malloc(sizeof(int) * size - 1);

	if (cpy == NULL)
		return;

	cp_array(array, cpy, size);

	mergesort(cpy, 0, size, array);
	free(cpy);
}
