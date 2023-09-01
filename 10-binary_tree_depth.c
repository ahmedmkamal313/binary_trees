#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree
 * @tree: Pointer to the node to measure the depth
 * Return: The depth of the node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	/* Check if tree is NULL */
	if (tree == NULL)
		return (0);

	/* Check if tree is the root */
	if (tree->parent == NULL)
		return (0);

	/* Return one plus the depth of the parent node */
	return (1 + binary_tree_depth(tree->parent));
}
