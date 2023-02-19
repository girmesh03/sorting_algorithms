#include "sort.h"
#include <string.h>

/**
 * merge - merge two arrays
 * @array: array to merge
 * @left: left array
 * @right: right array
 * @left_size: size of left array
 * @right_size: size of right array
 * @size: size of the array
 * Return: void
 */

void merge(int *array, int *left, int *right,
		   size_t left_size, size_t right_size, size_t size)
{
	int *temp;
	size_t i = 0, j = 0, k = 0;

	temp = malloc(sizeof(int) * size);
	if (temp == NULL)
	{
		return;
	}

	printf("Merging...\n[left]: ");
	while (i < left_size && j < right_size)
	{
		if (left[i] < right[j])
		{
			temp[k++] = left[i++];
		}
		else
		{
			temp[k++] = right[j++];
		}
	}

	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size)
	{
		temp[k++] = left[i++];
	}
	while (j < right_size)
	{
		temp[k++] = right[j++];
	}

	memcpy(array, temp, sizeof(int) * size);
	free(temp);
}

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge Sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */

void merge_sort(int *array, size_t size)
{
	int *left, *right;
	size_t left_size, right_size;

	if (size > 1)
	{
		left_size = size / 2;
		right_size = size - left_size;
		left = array;
		right = array + left_size;

		merge_sort(left, left_size);
		merge_sort(right, right_size);

		merge(array, left, right, left_size, right_size, size);
		printf("[Done]: ");
		print_array(array, size);
	}
}
