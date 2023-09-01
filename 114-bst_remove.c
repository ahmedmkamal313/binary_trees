#include "binary_trees.h"

/**
 * bst_successor - Finds the first in-order successor of a node
 * @node: Pointer to the node to find the successor
 * Return: Pointer to the successor node
 */
bst_t *bst_successor(bst_t *node)
{
	/* Check if node is NULL or has no right child */
	if (node == NULL || node->right == NULL)
		return (NULL);

	/* Move to the right child */
	node = node->right;

	/* Move to the leftmost node in the right subtree */
	while (node->left != NULL)
		node = node->left;

	/* Return the successor node */
	return (node);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to the root node of the tree where you will remove a node
 * @value: Value to remove in the tree
 * Return: Pointer to the new root node of
 * the tree after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *node, *successor, *parent;

	/* Check if root is NULL */
	if (root == NULL)
		return (NULL);
	node = bst_search(root, value);
	if (node == NULL)
		return (root);
	parent = node->parent;
	/* Check if node has two children */
	if (node->left != NULL && node->right != NULL)
	{
		/* Find the first in-order successor of the node */
		successor = bst_successor(node);
		/* Copy the successor's value to the node */
		node->n = successor->n;
		 /* Remove the successor instead of the node */
		node = successor;
	}
	if (node->left == NULL || node->right == NULL)
	{
		/* Get the child of the node or NULL if none */
		successor = (node->left != NULL) ? node->left : node->right;
		/* Check if node is not the root */
		if (parent != NULL)
		{
			if (parent->left == node)
				parent->left = successor;
			else
				parent->right = successor;
		}
		else /* Node is the root */
		{
			root = successor;
		}
		if (successor != NULL)
			successor->parent = parent;
		free(node);
	}
	return (root);
}
