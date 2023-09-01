#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree
 * @tree: Pointer to the root node of the tree to count the number of nodes
 * Return: The number of nodes with at least 1 child in the tree
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	/* Check if tree is NULL */
	if (tree == NULL)
		return (0);

	/* Check if tree is a leaf */
	if (tree->left == NULL && tree->right == NULL)
		return (0);

	/*
	 * Recursively count the nodes with at
	 * least 1 child in the left and right subtrees
	 */
	return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
