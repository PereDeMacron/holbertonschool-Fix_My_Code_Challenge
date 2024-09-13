#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes a node at a specific index from a list
 *
 * @head: A pointer to the first element of the list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp = *head;
	unsigned int i = 0;

	if (*head == NULL)
		return (-1);

	while (tmp && i < index)
	{
		tmp = tmp->next;
		i++;
	}

	if (tmp == NULL)
		return (-1);

	if (tmp == *head)
	{
		*head = tmp->next;
		if (*head)
			(*head)->prev = NULL;
	}
	else
	{
		if (tmp->prev)
			tmp->prev->next = tmp->next;
		if (tmp->next)
			tmp->next->prev = tmp->prev;
	}

	free(tmp);
	return (1);
}
