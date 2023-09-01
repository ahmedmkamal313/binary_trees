#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is full, otherwise 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int left_full, right_full;

	/* Check if tree is NULL */
	if (tree == NULL)
		return (0);

	/* Check if tree has no children */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* Recursively check if the left and right subtrees are full */
	left_full = binary_tree_is_full(tree->left);
	right_full = binary_tree_is_full(tree->right);

	/* Return 1 if both subtrees are full, otherwise 0 */
	return (left_full && right_full);
}
