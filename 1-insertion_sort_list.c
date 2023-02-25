#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: doubly linked list
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *pos;

	if (list == NULL || !*list)
	{
		return;
	}

	current = (*list)->next;

	while (current != NULL)
	{
		pos = current;
		while (pos->prev != NULL && pos->n < pos->prev->n)
		{
			pos->prev->next = pos->next;
			if (pos->next != NULL)
			{
				pos->next->prev = pos->prev;
			}
			pos->next = pos->prev;
			pos->prev = pos->prev->prev;
			pos->next->prev = pos;
			if (pos->prev == NULL)
			{
				*list = pos;
			}
			else
			{
				pos->prev->next = pos;
			}
			print_list(*list);
		}
		current = current->next;
	}
}
