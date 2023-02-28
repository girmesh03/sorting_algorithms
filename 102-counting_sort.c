#include "sort.h"
#include <string.h>

int find_max(int *array, size_t size);
void build_copy_array(int *array, int *count_array, size_t size);

/**
 * find_max - find the maximum value in an array
 * @array: array to search
 * @size: size of the array
 * Return: maximum value
 */

int find_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * build_copy_array - build the count array
 * @array: array to build the count array from
 * @count_array: count array
 * @size: size of the array
 * Return: void
 */

void build_copy_array(int *array, int *count_array, size_t size)
{
	int i, n = (int)size;
	int *output_array;

	/* allocate memory for output array */
	output_array = malloc(sizeof(int) * n);
	if (output_array == NULL)
	{
		free(count_array);
		return;
	}

	/* build the count array */
	for (i = n - 1; i >= 0; i--)
	{
		output_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}

	/* copy the output array to the original array */
	for (i = 0; i < n; i++)
		array[i] = output_array[i];

	/* free the memory */
	free(output_array);
	free(count_array);
}

/**
 * counting_sort - sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *count;
	int k, i, n = (int)size;

	if (array == NULL || n < 2)
		return;

	/* get the maximum value in the array */
	k = find_max(array, size);
	/* allocate memory for count array */
	count = malloc((k + 1) * sizeof(int));
	if (count == NULL)
		return;
	/* initialize count array all elements to 0 */
	memset(count, 0, (k + 1) * sizeof(int));
	/* count the frequency of each element in the array */
	/* and update the count array */
	for (i = 0; i < n; i++)
	{
		count[array[i]]++;
	}
	/* update the count array to store the actual position */
	for (i = 1; i <= k; i++)
	{
		count[i] += count[i - 1];
	}
	/* print the count array */
	print_array(count, k + 1);

	/* build the copy array */
	build_copy_array(array, count, size);
}
