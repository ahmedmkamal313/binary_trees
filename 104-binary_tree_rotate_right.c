#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree
 * @tree: Pointer to the root node of the tree to rotate
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	/* Check if tree is NULL or has no left child */
	if (tree == NULL || tree->left == NULL)
		return (tree);

	/* Save the left child as the new root */
	new_root = tree->left;

	/* Move the right child of the new root to the left of the old root */
	tree->left = new_root->right;
	if (new_root->right != NULL)
		new_root->right->parent = tree;

	/* Make the old root the right child of the new root */
	new_root->right = tree;
	tree->parent = new_root;

	/* Make the new root's parent NULL */
	new_root->parent = NULL;

	/* Return the new root */
	return (new_root);
}
