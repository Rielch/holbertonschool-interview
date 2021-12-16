#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - inserts a node in the singly linked list
 * @head: head of the linked list
 * @number: value of the node
 *
 * Return: new node or NULL if failed
 */

listint_t *insert_node(listint_t **head, int number)
{
  listint_t *new, *temp;

  new = malloc(sizeof(listint_t));
  if (new == NULL)
  {
    return (NULL);
  }
  new->n = number;
  if (number < (*head)->n)
  {
    new->next = *head;
    *head = new;
    return (new);
  }
  if (*head != NULL)
  {
    temp = *head;
    while (temp != NULL)
    {
      if (temp->next == NULL && temp->n < number)
      {
	temp->next = new;
	new->next = NULL;
	return (new);
      }
      else if (temp->next->n > number)
      {
	new->next = temp->next;
	temp->next = new;
	return (new);
      }
      temp = temp->next;
    }
  }
  new->next = NULL;
  *head = new;
  return (new);
}
