#include "binary_trees.h"

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
 * height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: The height of the tree
 */
int height(const binary_tree_t *tree)
{
	int left_height, right_height;

	/* Check if tree is NULL */
	if (tree == NULL)
		return (0);

	/* Recursively calculate the height of the left and right subtrees */
	left_height = height(tree->left);
	right_height = height(tree->right);

	/* Return the maximum of the two heights plus one */
	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * avl_helper - Helper function to check if a binary tree is an AVL tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is an AVL tree, otherwise 0
 */
int avl_helper(const binary_tree_t *tree)
{
	int balance;

	/* Check if tree is NULL */
	if (tree == NULL)
		return (1);

	/* Check if tree is a BST */
	if (!bst_helper(tree, INT_MIN, INT_MAX))
		return (0);

	/* Calculate the balance factor of the node */
	balance = height(tree->left) - height(tree->right);

	/* Check if balance factor is within the limit */
	if (balance < -1 || balance > 1)
		return (0);

	/* Recursively check if the left and right subtrees are AVL trees */
	return (avl_helper(tree->left) && avl_helper(tree->right));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	/* Check if tree is NULL */
	if (tree == NULL)
		return (0);

	/*
	 * Use helper function with minimum
	 * and maximum values as INT_MIN and INT_MAX
	 */
	return (avl_helper(tree));
}
