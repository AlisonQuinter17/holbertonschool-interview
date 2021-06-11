#include "lists.h"

/**
 * check_cycle - Checks if a singly linked list has a cycle in it.
 * @list: Pointer to head of list.
 * Return: 0 if there is no cycle, 1 if there is a cycle.
 */
int check_cycle(listint_t *list)
{
	listint_t *hare = list, *turtle = list;

	if (list == NULL)
		return (0);

	while (hare && turtle && hare->next)
	{
		turtle = turtle->next;
		hare = hare->next->next;

		if (turtle == hare)
			return (1);
	}
	return (0);
}
