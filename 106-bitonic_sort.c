#include "sort.h"

void bitonic_merge(int *array, size_t start, size_t size, int up);
void bitonic_sort_recursive(int *array, size_t start, size_t size, int up);

/**
 * bitonic_merge - sorts an array of integers in ascending order using
 * the Bitonic sort algorithm
 * @array: array to sort
 * @start: start index of array
 * @size: size of array
 * @up: direction of sorting
 * Return: void
 */

void bitonic_merge(int *array, size_t start, size_t size, int up)
{
	size_t half, i;
	int temp;

	if (size > 1)
	{
		half = size / 2;

		for (i = start; i < start + half; i++)
		{
			if ((array[i] > array[i + half]) == up)
			{
				temp = array[i];
				array[i] = array[i + half];
				array[i + half] = temp;
			}
		}

		bitonic_merge(array, start, half, up);
		bitonic_merge(array, start + half, half, up);
	}
}

/**
 * bitonic_sort_recursive - sorts an array of integers in ascending order using
 * the Bitonic sort algorithm
 * @array: array to sort
 * @start: start index of array
 * @size: size of array
 * @up: direction of sorting
 * Return: void
 */

void bitonic_sort_recursive(int *array, size_t start, size_t size, int up)
{
	size_t half;

	if (size > 1)
	{
		half = size / 2;

		if (up >= 1)
		{
			printf("Merging [%lu/%lu] (UP):\n", size, size);
			print_array(&array[start], size);
		}
		else
		{
			printf("Merging [%lu/%lu] (DOWN):\n", size, size);
			print_array(&array[start], size);
		}

		bitonic_sort_recursive(array, start, half, 1);
		bitonic_sort_recursive(array, start + half, half, 0);

		bitonic_merge(array, start, size, up);

		if (up >= 1)
		{
			printf("Result [%lu/%lu] (UP):\n", size, size);
			print_array(&array[start], size);
		}
		else
		{
			printf("Result [%lu/%lu] (DOWN):\n", size, size);
			print_array(&array[start], size);
		}
	}
}

/**
 * bitonic_sort - sorts an array of integers in ascending order using the
 * Bitonic sort algorithm
 * @array: array to sort
 * @size: size of array
 * Return: void
 */

void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_recursive(array, 0, size, 1);
}
