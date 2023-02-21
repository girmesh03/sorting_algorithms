#include "sort.h"

void swap(int *a, int *b);
int hoare_partition(int *array, int low, int high, size_t size);
void quick_sort_helper(int *array, int low, int high, size_t size);

/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * hoare_partition - partitions an array of integers around a pivot
 * @array: array to partition
 * @low: start index of array
 * @high: end index of array
 * @size: size of array
 * Return: index of pivot
 */

int hoare_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
		{
			return (j);
		}

		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * quick_sort_helper - sorts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: array to sort
 * @low: start index of array
 * @high: end index of array
 * @size: size of array
 * Return: void
 */

void quick_sort_helper(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = hoare_partition(array, low, high, size);
		quick_sort_helper(array, low, pivot - 1, size);
		quick_sort_helper(array, pivot, high, size);
	}
}

/**
 * quick_sort_hoare - sorts an array of integers in ascending order using
 * the Quick sort algorithm
 * @array: array to sort
 * @size: size of array
 * Return: void
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	quick_sort_helper(array, 0, size - 1, size);
}
