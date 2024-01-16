#include "sort.h"

/**
 * insertion_sort_list - sort given list using insertion
 * @list: targeted link list
 *
 * Return: void, doesnt return
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	listint_t *curr = (*list)->next, *temp;

	while (curr != NULL)
	{
		temp = curr;
		while (temp->prev != NULL && temp->n < temp->prev->n)
		{
			temp->prev->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = temp->prev;

			temp->next = temp->prev;
			temp->prev = temp->prev->prev;
			if (temp->prev != NULL)
				temp->prev->next = temp;
			else
				*list = temp;
			temp->next->prev = temp;
			print_list(*list);
		}
		curr = curr->next;
	}
}
