#include "sort.h"
void merge_recurs(size_t lt, size_t rt, int *array, int *bs);
/**
 * merge_sort - entry
 * @array: var
 * @size: var
 */
void merge_sort(int *array, size_t size)
{
	size_t i = 0;
	int *bs = NULL;

	if (size < 2 || array == NULL)
		return;
	bs = malloc(sizeof(int) * size);
	if (bs == NULL)
		return;
	while (i < size)
	{
		bs[i] = array[i];
		i++;
	}
	merge_recurs(0, size, array, bs);
	free(bs);
}
/**
 * merge - entry
 * @lt: var
 * @md: var
 * @rt: var
 * @dest: var
 * @src: var
 */
void merge(size_t lt, size_t md, size_t rt, int *dest, int *src)
{
	size_t i = 0;
	size_t j = 0, k = 0;

	printf("Mergign...\n");
	printf("[left]: ");
	print_array(src + lt, md - lt);
	printf("[right]: ");
	print_array(src + md, rt - md);

	j = md;
	i = lt;
	k = lt;

	for (; k < rt; k++)
	{
		if (i < md && (j >= rt || src[i] <= src[j]))
		{
			dest[k] = src[i];
			i++;
		}
		else
		{
			dest[k] = src[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(dest + lt, rt - lt);
}
/**
 * merge_recurs - entry
 * @lt: var
 * @rt: var
 * @array: var
 * @bs: var
 */
void merge_recurs(size_t lt, size_t rt, int *array, int *bs)
{
	size_t md = 0;

	if (rt - lt < 2)
		return;
	md = (lt + rt) / 2;
	merge_recurs(lt, md, array, bs);
	merge_recurs(md, rt, array, bs);
	merge(lt, md, rt, array, bs);

	md = lt;
	while (md < rt)
	{
		bs[md] = array[md];
		md++;
	}
}
