#include "sort.h"

/**
 * swap - swap to pointers value
 * @a: first value
 * @b: second value
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;

}

/**
 * partition - dived the array and sorts it
 * @array: targeted array
 * @start: first position of array
 * @end: last position of array
 * @size: size of array
 *
 * Return: the pivot point of the array
 */
int partition(int *array, int start, int end, size_t size)
{
	int pivot;
	int i, j;

	pivot = array[end];
	i = start - 1;
	for (j = start; j <= end - 1; j++)
	{
		if (array[j] <= pivot)
		{
			++i;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (i + 1 != end)
	{
		swap(&array[i + 1], &array[end]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * recursion - use recursion to sort array
 * @array: targeted array
 * @start: first position of array
 * @end: last position of array
 * @size: sizes of array
 *
 * Return: void, doesnt return
 */
void recursion(int *array, int start, int end, size_t size)
{
	int pivot;

	if (start < end)
	{
		pivot = partition(array, start, end, size);
		recursion(array, start, pivot - 1, size);
		recursion(array, pivot + 1, end, size);
	}
}

/**
 * quick_sort - sort using quick sorting
 * @array: targeted array to sort
 * @size: size of the targeted array
 *
 * Return: void, doesnt return
 */
void quick_sort(int *array, size_t size)
{
	int start = 0;
	int end;

	if (array == NULL || size < 2)
		return;
	end = (size - 1);
	recursion(array, start, end, size);
}
