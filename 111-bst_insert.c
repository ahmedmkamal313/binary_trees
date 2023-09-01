#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *node;
	bst_t *parent;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		node = binary_tree_node(NULL, value);
		if (node == NULL)
			return (NULL);
		*tree = node;
		return (node);
	}
	parent = *tree;
	while (1)
	{
		if (value == parent->n)
			return (NULL);

		if (value < parent->n)
		{
			if (parent->left == NULL)
				break;
			parent = parent->left;
		}
		else /* Value is greater than parent's value */
		{
			if (parent->right == NULL)
				break;
			parent = parent->right;
		}
	}
	node = binary_tree_node(parent, value);
	if (node == NULL)
		return (NULL);
	if (value < parent->n)
		parent->left = node;
	else
		parent->right = node;
	return (node);
}
