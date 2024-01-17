#include "sort.h"

/**
 * selection_sort - sort data using selection sort
 * @array: targeted array to sort
 * @size: size of targeted array
 *
 * Return: void, doesnt return
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, small;
	int temp;

	if (array == NULL || size < 2)
		return;
	for (i = 0; i < (size - 1); i++)
	{
		small = i;
		for (j = (i + 1); j < size; j++)
		{
			if (array[small] > array[j])
				small = j;
		}
		if (small != i)
		{
			temp = array[i];
			array[i] = array[small];
			array[small] = temp;
			print_array(array, size);
		}
	}
}
