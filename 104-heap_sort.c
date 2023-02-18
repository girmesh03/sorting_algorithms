#include "sort.h"

/**
 * sift_down - sift down
 * @array: array to sift down
 * @start: start index
 * @end: end index
 * @size: size of the array
 * Return: void
 */

void sift_down(int *array, int start, int end, size_t size)
{
	int root = start;
	int child, temp;

	while (root * 2 + 1 <= end)
	{
		child = root * 2 + 1;

		if (child + 1 <= end && array[child] < array[child + 1])
			child = child + 1;

		if (array[root] < array[child])
		{
			temp = array[root];
			array[root] = array[child];
			array[child] = temp;
			/*printf("Swap: %d %d\n", array[root], array[child]);*/
			print_array(array, size);
			root = child;
		}
		else
		{
			return;
		}
	}
}

/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: array to sort
 * @size: size of the array
 * Return: void
 */

void heap_sort(int *array, size_t size)
{
	int start = (size - 2) / 2;
	int end, temp;

	while (start >= 0)
	{
		sift_down(array, start, size - 1, size);
		start--;
	}

	end = size - 1;

	while (end > 0)
	{
		temp = array[end];
		array[end] = array[0];
		array[0] = temp;
		/*printf("Swap: %d %d\n", array[end], array[0]);*/
		print_array(array, size);
		end--;
		sift_down(array, 0, end, size);
	}
}
