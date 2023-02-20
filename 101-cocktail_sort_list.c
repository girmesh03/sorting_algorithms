#include "sort.h"
#include <stdbool.h>

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @node1: first node
 * @node2: second node
 * @list: doubly linked list
 */

void swap_nodes(listint_t *node1, listint_t *node2, listint_t **list)
{
	listint_t *prev, *next;

	prev = node1->prev;
	next = node2->next;

	if (prev != NULL)
		prev->next = node2;
	else
		*list = node2;

	if (next != NULL)
		next->prev = node1;

	node1->prev = node2;
	node1->next = next;
	node2->prev = prev;
	node2->next = node1;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: doubly linked list to sort
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *current, *tail;
	bool swapped = true;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = *list;
	tail = NULL;

	while (swapped)
	{
		swapped = false;
		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(current, current->next, list);
				print_list(*list);
				swapped = true;
			}
			else
				current = current->next;
		}
		if (!swapped)
			break;
		tail = current;
		swapped = false;

		while (tail->prev != NULL)
		{
			if (tail->n < tail->prev->n)
			{
				swap_nodes(tail->prev, tail, list);
				print_list(*list);
				swapped = true;
			}
			else
				tail = tail->prev;
		}
		current = tail;
	}
}
