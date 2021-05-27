#include "lists.h"

/**
 * is_palindrome - Checks if a singly linked list is a palindrome.
 * @head: Double pointer to list.
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome.
 */
int is_palindrome(listint_t **head)
{
	listint_t *aux = *head;
	int len = 0;

	while (aux->next)
	{
		aux = aux->next;
		len++;
	}

	(*head) = (*head)->next;
	return (recursive((*head), len - 2));
}

/**
 * recursive - Compare the start to end of the new list.
 * @head: Pointer to the head of the list.
 * @len: New lenght of the list.
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome.
 */
int recursive(listint_t *head, int len)
{
	listint_t *aux = head;
	int i = 0;

	if (len < 2)
		return (1);

	while (i < len)
	{
		aux = aux->next;
		i++;
	}
	if (head->n == aux->n)
	{
		head = head->next;
		return (recursive(head, len - 2));
	}
	else
		return (0);
}
