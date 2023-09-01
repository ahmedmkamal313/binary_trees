#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle
 * Return: Pointer to the uncle node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	/* Check if node or grandparent is NULL */
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	/* Check if node's parent is the left child of its grandparent */
	if (node->parent == node->parent->parent->left)
		/* Return the right child of the grandparent */
		return (node->parent->parent->right);

	/* Otherwise, node's parent is the right child of its grandparent */
	/* Return the left child of the grandparent */
	return (node->parent->parent->left);
}
