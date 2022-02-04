#include "lists.h"

/**
 * check_cycle - Check if a singly linked list has a cycle in it
 *
 * @list: Pointer to the head of the singly linked list
 * Return: 0 if there is no cycle and 1 if there is a cycle
 */

int check_cycle(listint_t *list)
{
  listint_t *fast = list, *slow = list;

  while (fast != NULL)
  {
    if (slow->next != NULL)
      slow = slow->next;
    if (fast->next != NULL)
      fast = fast->next->next;
    else
      return(0);
    if (fast == slow)
      return(1);
  }
  return(0);
}
