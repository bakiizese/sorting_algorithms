#include "sort.h"
void swap(int *x, int *y, int size, int array[])
{
    int tm = *x;
    *x = *y;
    *y = tm;
    print_array(array, size);
}

int partition(int array[], int low, int high, int size)
{
    int piv_value = array[high];
    int i = low;
    int j;

    for (j = low; j < high; j++)
    {
        if (array[j] <= piv_value)
        {
            swap(&array[i], &array[j], size, array);
            i++;
        }
    }
    swap(&array[i], &array[high], size, array);
    return i;
}

void recurse(int array[], int low, int high, int size)
{
    if (low < high)
    {
        int piv_point = partition(array, low, high, size);
        recurse(array, low, piv_point - 1, size);
        recurse(array, piv_point + 1, high, size);
    }
}
void quick_sort(int *array, size_t size)
{
    recurse(array, 0, size - 1, size);
}
