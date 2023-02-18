#include "sort.h"

void merge(int *array, int *left_array, int *right_array,
		   int left_size, int right_size, int size);
void merge_sort(int *array, size_t size);
/**
 * merge - merge two arrays
 * @array: array to sort
 * @left_array: left array
 * @right_array: right array
 * @left_size: size of left array
 * @right_size: size of right array
 * @size: size of the array
 */
void merge(int *array, int *left_array, int *right_array,
		   int left_size, int right_size, int size)
{
	int *temp = malloc(sizeof(int) * size);
	int i = 0, j = 0, k = 0;

	printf("Merging...\n");
	while (i < left_size && j < right_size)
	{
		if (left_array[i] <= right_array[j])
		{
			temp[k++] = left_array[i++];
		}
		else
		{
			temp[k++] = right_array[j++];
		}
	}
	if (i > left_size)
	{
		while (j < right_size)
		{
			temp[k++] = right_array[j++];
		}
	}
	else
	{
		while (i <= left_size)
		{
			temp[k++] = left_array[i++];
		}
	}
	printf("[left]: ");
	print_array(left_array, left_size);
	printf("[right]: ");
	print_array(right_array, right_size);
	printf("[Done]: ");
	print_array(temp, size);
	for (i = 0; i < size; i++)
	{
		array[i] = temp[i];
	}
	free(temp);
}
/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge Sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *left_array, *right_array;
	size_t left_size, right_size;

	if (size > 1)
	{
		left_size = size / 2;
		right_size = size - left_size;
		left_array = array;
		right_array = array + left_size;

		merge_sort(left_array, left_size);
		merge_sort(right_array, right_size);
		merge(array, left_array, right_array,
			  left_size, right_size, size);
	}
}
