#include "sort.h"

/**
 * bubble_sort - sort data using bubble sorting
 * @array: targeted array to sort
 * @size: size of the targeted array
 *
 * Return: void, doesnt return
 */
void bubble_sort(int *array, size_t size)
{
	int temp;
	size_t i, j;

	if (size >= 2 && array != NULL)
	{
		for (i = 0; i < (size - 1); i++)
		{
			for (j = 0; j < (size - i - 1); j++)
			{
				if (array[j] > array[j + 1])
				{
					temp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = temp;
					print_array(array, size);
				}
			}
		}
	}
}
