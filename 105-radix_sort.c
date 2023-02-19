#include "sort.h"

/**
 * modified_counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * @output: array to store the sorted array
 * @position: position of the digit to be sorted
 * Return: void
 */

void modified_counting_sort(int *array, size_t size, int *output, int position)
{
	int i, count[10] = {0};

	for (i = 0; i < (int)size; i++)
		count[(array[i] / position) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = (int)size - 1; i >= 0; i--)
	{
		output[count[(array[i] / position) % 10] - 1] = array[i];
		count[(array[i] / position) % 10]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];
}

/**
 * radix_sort - sorts an array of integers in ascending order using the
 * Radix sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */

void radix_sort(int *array, size_t size)
{
	int max, position, i;
	int *output;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	for (position = 1; max / position > 0; position *= 10)
	{
		modified_counting_sort(array, size, output, position);
		print_array(array, size);
	}

	free(output);
}
