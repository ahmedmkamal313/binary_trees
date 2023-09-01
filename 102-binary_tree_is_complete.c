#include "binary_trees.h"
#include <stdlib.h>

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
	return (1 + binary_tree_size(tree->left) +
			binary_tree_size(tree->right));
}

/**
 * is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * @index: The index assigned to the current node
 * @size: The size of the tree
 * Return: 1 if the tree is complete, otherwise 0
 */
int is_complete(const binary_tree_t *tree, size_t index, size_t size)
{
	/* Check if tree is NULL */
	if (tree == NULL)
		return (1);

	/* Check if index exceeds size */
	if (index >= size)
		return (0);

	/* Recursively check if the left and right subtrees are complete */
	return (is_complete(tree->left, 2 * index + 1, size) &&
			is_complete(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 * Return: 1 if the tree is complete, otherwise 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	/* Check if tree is NULL */
	if (tree == NULL)
		return (0);

	/* Calculate the size of the tree */
	size = binary_tree_size(tree);

	/* Check if the tree is complete using index-based approach */
	return (is_complete(tree, 0, size));
}
