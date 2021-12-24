#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - Creates a new node for a binary tree
 *
 * @parent: parent node of the binary tree
 * @value: value to insert in the node
 * Return: Pointer to the new node or NULL if failed
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
  binary_tree_t *new = malloc(sizeof(binary_tree_t));

  if (new == NULL)
  {
    return (NULL);
  }
  new->parent = parent;
  new->left = NULL;
  new->right = NULL;
  new->n = value;
  return (new);
}
