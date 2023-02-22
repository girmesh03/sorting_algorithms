#include "sort.h"

/**
 * swap - sorts an array of integers in ascending order
 * @arr: array to be sorted
 * @pivot_index: temporary pivot index
 * @j: index, used to swap
 * @size: size of the array
 * Return: void
 */

void swap(int arr[], int pivot_index, int j, size_t size)
{
	int temp = arr[pivot_index];

	arr[pivot_index] = arr[j];
	arr[j] = temp;

	if (arr[pivot_index] != arr[j])
		print_array(arr, size);
}

/**
 * partition - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @start: start index
 * @end: end index
 * @size: size of the array
 * Return: pivot_index index
 */

int partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int pivot_index = start;
	int i;

	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			swap(array, pivot_index, i, size);
			pivot_index++;
		}
	}

	swap(array, pivot_index, end, size);

	return (pivot_index);
}

/**
 * quick_sort_helper - sorts an array of integers in ascending order
 * @array: array to be sorted
 * @start: start index
 * @end: end index
 * @size: size of the array
 * Return: void
 */

void quick_sort_helper(int *array, int start, int end, size_t size)
{
	int pivot_index;

	if (start < end)
	{
		pivot_index = partition(array, start, end, size);
		quick_sort_helper(array, start, pivot_index - 1, size);
		quick_sort_helper(array, pivot_index + 1, end, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm and Lomuto partition scheme
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}
