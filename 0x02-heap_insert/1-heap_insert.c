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
new = heap_sort(new);
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
if (deep_node(node->left) > deep_node(node->right))
{
new = insert_last_heap(&node->right, value);
}
else
{
new = insert_last_heap(&node->left, value);
}
return (new);
}

/**
 * deep_node - calculates the deep of a binary_tree
 *
 * @node: root of the binary tree
 * Return: Deep of the tree
 */

int deep_node(heap_t *node)
{
if (node == NULL)
return (0);

return (deep_node(node->right) + 1);
}

/**
 * heap_sort - sort the node in the heap
 *
 * @node: node to sort
 * Return: Void
 */

heap_t *heap_sort(heap_t *node)
{
int temp;

if (node->parent == NULL || node->n < node->parent->n)
return (node);
if (node->n > node->parent->n)
{
temp = node->n;
node->n = node->parent->n;
node->parent->n = temp;
return (heap_sort(node->parent));
}
return (node);
}
