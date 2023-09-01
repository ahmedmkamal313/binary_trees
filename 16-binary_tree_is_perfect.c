#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 * Return: The height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	/* Check if tree is NULL */
	if (tree == NULL)
		return (0);

	/* Check if tree has no children */
	if (tree->left == NULL && tree->right == NULL)
		return (0);

	/* Recursively calculate the height of the left and right subtrees */
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	/* Return one plus the maximum of the subtree heights */
	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure the size
 * Return: The size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	/* Check if tree is NULL */
	if (tree == NULL)
		return (0);

	/* Recursively calculate the size of the left and right subtrees */
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is perfect, otherwise 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, size;

	/* Check if tree is NULL */
	if (tree == NULL)
		return (0);

	/* Calculate the height and size of the tree */
	height = binary_tree_height(tree);
	size = binary_tree_size(tree);

	/*
	 * Check if the size is equal to 2^(height + 1) - 1,
	 * which is true for a perfect binary tree
	 */
	return (size == ((size_t)1 << (height + 1)) - 1);
}
