#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 * @node: Pointer to the node to find the sibling
 * Return: Pointer to the sibling node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	/* Check if node or parent is NULL */
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* Check if node is the left child of its parent */
	if (node == node->parent->left)
		/* Return the right child of the parent */
		return (node->parent->right);

	/* Otherwise, node is the right child of its parent */
	/* Return the left child of the parent */
	return (node->parent->left);
}
