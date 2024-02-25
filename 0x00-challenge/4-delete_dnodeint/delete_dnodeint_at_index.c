#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
    dlistint_t *current, *tmp;
    unsigned int i;

    if (*head == NULL)
        return (-1);

    current = *head;

    // Special case: if deleting the first node
    if (index == 0)
    {
        *head = current->next;
        if (*head != NULL)
            (*head)->prev = NULL;
        free(current);
        return (1);
    }

    // Traverse to the node at the specified index
    for (i = 0; current != NULL && i < index; i++)
    {
        current = current->next;
    }

    // Check if the given index is valid
    if (current == NULL)
        return (-1);

    // Adjust pointers to skip the node to be deleted
    current->prev->next = current->next;
    
    if (current->next != NULL)
        current->next->prev = current->prev;

    // Free the node
    free(current);

    return (1);
}
