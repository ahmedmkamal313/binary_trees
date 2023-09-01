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

	/* Check if tree is NULL */
	if (tree == NULL)
		return (NULL);

	/* Check if tree is empty */
	if (*tree == NULL)
	{
		/* Create a new node as the root */
		node = binary_tree_node(NULL, value);
		if (node == NULL)
			return (NULL);
		*tree = node;
		return (node);
	}

	/* Find the parent of the new node */
	parent = *tree;
	while (1)
	{
		/* Check if value is already present in the tree */
		if (value == parent->n)
			return (NULL);

		/* Check if value is less than parent's value */
		if (value < parent->n)
		{
			/* Check if parent has no left child */
			if (parent->left == NULL)
				break;
			/* Move to the left child */
			parent = parent->left;
		}
		else /* Value is greater than parent's value */
		{
			/* Check if parent has no right child */
			if (parent->right == NULL)
				break;
			/* Move to the right child */
			parent = parent->right;
		}
	}

	/* Create a new node with parent as its parent */
	node = binary_tree_node(parent, value);
	if (node == NULL)
		return (NULL);

	/* Attach the new node as the left or right child of its parent */
	if (value < parent->n)
		parent->left = node;
	else
		parent->right = node;

	/* Return the new node */
	return (node);
}
