#include "binary_trees.h"
#include <limits.h>

/**
 * bst_helper - Helper function to check if a binary tree is a BST
 * @tree: Pointer to the root node of the tree to check
 * @min: The minimum value allowed in the subtree
 * @max: The maximum value allowed in the subtree
 * Return: 1 if the tree is a BST, otherwise 0
 */
int bst_helper(const binary_tree_t *tree, int min, int max)
{
	/* Check if tree is NULL */
	if (tree == NULL)
		return (1);

	/* Check if tree's value is out of range */
	if (tree->n < min || tree->n > max)
		return (0);

	/* Recursively check if the left and right subtrees are BSTs */
	return (bst_helper(tree->left, min, tree->n - 1) &&
			bst_helper(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	/* Check if tree is NULL */
	if (tree == NULL)
		return (0);

	return (bst_helper(tree, INT_MIN, INT_MAX));
}
