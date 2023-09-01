#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: Pointer to the node to insert the right-child in
 * @value: Value to store in the new node
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/* Check if parent is NULL */
	if (parent == NULL)
		return (NULL);
	/* Allocate memory for the new node */
	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	/* Initialize the data and pointers of the new node */
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;

	/* Check if parent already has a right-child */
	if (parent->right != NULL)
	{
		/* Set the new node as the right-child of the parent */
		new_node->right = parent->right;
		/* Set the parent of the old right-child as the new node */
		parent->right->parent = new_node;
	}
	else
	{
		/* Set the new node as the right-child of the parent */
		new_node->right = NULL;
	}
	/* Set the parent's right pointer as the new node */
	parent->right = new_node;

	return (new_node);
}
