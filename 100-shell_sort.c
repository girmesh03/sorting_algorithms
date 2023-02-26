#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using the Shell
 * sort algorithm, using the Knuth sequence
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */

void shell_sort(int *array, size_t size)
{
	int gap = 1;
	int i, j, temp;
	int n = (int)size;

	if (array == NULL || size < 2)
	{
		return;
	}

	while (gap < n / 3)
	{
		gap = 3 * gap + 1;
	}

	while (gap > 0)
	{
		for (i = gap; i < n; i++)
		{
			temp = array[i];
			j = i - gap;

			while (j >= 0 && array[j] > temp)
			{
				array[j + gap] = array[j];
				j -= gap;
			}

			array[j + gap] = temp;
		}

		print_array(array, size);

		gap = (gap - 1) / 3;
	}
}
