#include "sort.h"

/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 * Return: void
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * partition - partitions the array
 * @array: array to be partitioned
 * @low: low index
 * @high: high index
 * @size: size of the array
 * Return: partition index
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int start = low - 1;
	int end = high;

	while (start < end)
	{
		while (array[start] <= pivot)
			start++;
		while (array[end] > pivot)
			end--;
		if (start < end)
		{
			swap(&array[start], &array[end]);
			print_array(array, size);
		}
	}

	swap(&array[low], &array[end]);
	return (end);
}

/**
 * quick_sort_helper - helper function for quick sort
 * @array: array to be sorted
 * @low: low index
 * @high: high index
 * @size: size of the array
 * Return: void
 */

void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int loc;

	if (low < high)
	{
		loc = partition(array, low, high - 1, size);
		quick_sort_helper(array, low, loc - 1, size);
		quick_sort_helper(array, loc + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using the
 * Quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	quick_sort_helper(array, 0, size, size);
}
