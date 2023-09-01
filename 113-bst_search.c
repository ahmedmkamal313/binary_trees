#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree
 * @tree: Pointer to the root node of the BST to search
 * @value: Value to search in the tree
 * Return: Pointer to the node containing a value equals to value
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	/* Check if tree is NULL */
	if (tree == NULL)
		return (NULL);

	/* Check if value is equal to node's value */
	if (value == tree->n)
		return ((bst_t *)tree);

	/* Check if value is less than node's value */
	if (value < tree->n)
		/* Recursively search in the left subtree */
		return (bst_search(tree->left, value));

	/* Otherwise, value is greater than node's value */
	/* Recursively search in the right subtree */
	return (bst_search(tree->right, value));
}
