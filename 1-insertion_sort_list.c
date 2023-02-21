#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: doubly linked list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *forward, *backward;

	if (!list || !*list)
		return;

	forward = (*list)->next;

	while (forward)
	{
		backward = forward->prev;

		while (backward && backward->n > forward->n)
		{
			if (backward->prev)
				backward->prev->next = forward;
			else
				*list = forward;

			if (forward->next)
				forward->next->prev = backward;

			backward->next = forward->next;
			forward->prev = backward->prev;
			backward->prev = forward;
			forward->next = backward;

			backward = forward->prev;
			print_list(*list);
		}
		forward = forward->next;
	}
}
