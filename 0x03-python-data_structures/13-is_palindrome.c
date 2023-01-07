#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: The head of the singly linked list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *a = *head;
	listint_t *b = *head;

	if (*head == NULL)
		return (1);

	while (b && b->next && b->next->next)
	{
		a = a->next;
		b = b->next->next;
	}

	a = reverse_list(&a);
	b = *head;
	while (a && b)
	{
		if (a->n != b->n)
			return (0);
		a = a->next;
		b = b->next;
	}

	return (1);
}

/**
 * reverse_list - Reverse a linked list
 * @head: The list
 * Return: Pointer to the new head
 * listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
 */
listint_t *reverse_list(listint_t **head)
{
	listint_t *prev = NULL;
	listint_t *next = NULL;

	while (*head)
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
		*head = next;
	}

	*head = prev;
	return (*head);
}

