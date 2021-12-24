#include "binary_trees.h"
#include <stdlib.h>

/**
 * heap_insert - inserts a node in a binary tree
 *
 * @root: root node of the binary tree
 * @value: value of the new node
 * Return: pointer to the new node or NULL if failed
 */

heap_t *heap_insert(heap_t **root, int value)
{
heap_t *new;

 if (root == NULL)
   {
     return (NULL);
   }
 if (*root == NULL)
   {
     new = binary_tree_node(*root, value);
     *root = new;
   }
 else
   {
     new = insert_last_heap(root, value);
     heap_sort(new);
   }
 return (new);
}

/**
 * insert_last_heap - inserts a new node at the end of the heap
 *
 * @root: root of the tree
 * @value: value of the node
 * Return: Pointer to the new node or NULL if failed
 */

heap_t *insert_last_heap(heap_t **root, int value)
{
  heap_t *node = *root, *new;

  if (node->left == NULL)
    {
      new = binary_tree_node(node, value);
      node->left = new;
      return (new);
    }
  else if (node->right == NULL)
    {
      new = binary_tree_node(node, value);
      node->right = new;
      return (new);
    }
  new = insert_last_heap(&node->left, value);
  return (new);
}

/**
 * heap_sort - sort the node in the heap
 *
 * @node: node to sort
 * Return: Void
 */

void heap_sort(heap_t *node)
{
  int temp;

  if (node->n < node->parent->n)
    return;
  while (node->n > node->parent->n)
    {
      temp = node->parent->n;
      node->parent->n = node->n;
      node->n = temp;
    }
}
