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

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 * Return: Pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t first_depth, second_depth;

	/* Check if first or second is NULL */
	if (first == NULL || second == NULL)
		return (NULL);

	/* Calculate the depth of first and second */
	first_depth = binary_tree_depth(first);
	second_depth = binary_tree_depth(second);

	/* Move up the deeper node until both nodes have the same depth */
	while (first_depth > second_depth)
	{
		first = first->parent;
		first_depth--;
	}
	while (second_depth > first_depth)
	{
		second = second->parent;
		second_depth--;
	}
	/* Move up both nodes until they are equal or reach the root */
	while (first != second && first && second)
	{
		first = first->parent;
		second = second->parent;
	}

	/* Return the common ancestor or NULL if none */
	return ((binary_tree_t *)first);
}
