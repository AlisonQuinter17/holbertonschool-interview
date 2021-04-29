#include "lists.h"

/**
 * insert_node - Inserts a number into a sorted singly linked list.
 * @head: Double pointer to head of list.
 * @number: Number to insert.
 * Return: The address of the new node, or NULL if it failed.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new_node = NULL;
	listint_t *current = *head;

	new_node = malloc(sizeof(listint_t));
	if (!new_node)
	{
		return (NULL);
	}
	new_node->n = number;

	if (!(*head) || new_node->n < (*head)->n)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}
	else
	{
		while (current->next != NULL)
		{
			if (current->next->n >= new_node->n)
			{
				new_node->next = current->next;
				current->next = new_node;
				return (new_node);
			}
			current = current->next;
		}
	}
	new_node->next = current->next;
	current->next = new_node;
	return (new_node);
}
