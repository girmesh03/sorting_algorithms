#include "sort.h"

void merge(int *array, int left_size, int right_size);

/**
 * merge - merge two subarrays
 * @array: array to sort
 * @left_size: size of left subarray
 * @right_size: size of right subarray
 */

void merge(int *array, int left_size, int right_size)
{
	int *temp;
	int i = 0, j = 0, k = 0;

	temp = malloc(sizeof(int) * (left_size + right_size));
	if (temp == NULL)
	{
		return;
	}

	printf("Merging...\n[left]: ");
	print_array(array, left_size);
	printf("[right]: ");
	print_array(array + left_size, right_size);

	while (i < left_size && j < right_size)
	{
		if (array[i] <= array[left_size + j])
		{
			temp[k++] = array[i++];
		}
		else
		{
			temp[k++] = array[left_size + j++];
		}
	}

	while (i < left_size)
	{
		temp[k++] = array[i++];
	}

	while (j < right_size)
	{
		temp[k++] = array[left_size + j++];
	}

	printf("[Done]: ");
	print_array(temp, left_size + right_size);

	for (i = 0; i < left_size + right_size; i++)
	{
		array[i] = temp[i];
	}

	free(temp);
}

/**
 * merge_sort - merge sort algorithm
 * @array: array to sort
 * @size: size of array
 */

void merge_sort(int *array, size_t size)
{
	if (size > 1)
	{
		int left_size = size / 2;
		int right_size = size - left_size;

		merge_sort(array, left_size);
		merge_sort(array + left_size, right_size);
		merge(array, left_size, right_size);
	}
}
