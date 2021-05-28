#include "lists.h"

/**
 * is_palindrome - Checks if a singly linked list is a palindrome.
 * @head: Double pointer to list.
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome.
 */
int is_palindrome(listint_t **head)
{
	return (detection(head, *head));
}

/**
 * detection - Detect if a list is palindrome.
 * @head: Double Pointer to the head node of the list, far left.
 * @aux: Pointer to copy of head, far right.
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome.
 */
int detection(listint_t **head, listint_t *aux)
{
	return ((!aux) || (detection(head, aux->next) && (*head)->n == aux->n ?
			   ((*head) = (*head)->next), 1 : 0));
}
