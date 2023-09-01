#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	/* Check if tree is NULL or has no right child */
	if (tree == NULL || tree->right == NULL)
		return (tree);

	/* Save the right child as the new root */
	new_root = tree->right;
	/* Move the left child of the new root to the right of the old root */
	tree->right = new_root->left;
	if (new_root->left != NULL)
		new_root->left->parent = tree;

	/* Make the old root the left child of the new root */
	new_root->left = tree;
	tree->parent = new_root;

	/* Make the new root's parent NULL */
	new_root->parent = NULL;

	/* Return the new root */
	return (new_root);
}
