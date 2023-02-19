#include "sort.h"
#include <string.h>
/**
 * counting_sort - sorts an array of integers in ascending order using the
 * Counting sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output;
	int k, i, n = (int)size;

	if (array == NULL || n < 2)
		return;
	k = array[0];

	for (i = 1; i < n; i++)
	{
		if (array[i] > k)
			k = array[i];
	}

	count = malloc((k + 1) * sizeof(int));
	if (count == NULL)
		return;
	memset(count, 0, (k + 1) * sizeof(int));
	for (i = 0; i < n; i++)
	{
		count[array[i]]++;
	}
	for (i = 1; i <= k; i++)
	{
		count[i] += count[i - 1];
	}

	print_array(count, k + 1);
	output = malloc(n * sizeof(int));

	for (i = n - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}
	for (i = 0; i < n; i++)
	{
		array[i] = output[i];
	}
	free(count);
	free(output);
}
