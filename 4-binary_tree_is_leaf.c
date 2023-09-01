#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Checks if a node is a leaf
 * @node: Pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	/* Check if node is NULL */
	if (node == NULL)
		return (0);

	/* Check if node has no children */
	if (node->left == NULL && node->right == NULL)
		return (1);

	/* Otherwise, node is not a leaf */
	return (0);
}
