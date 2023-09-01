#include "binary_trees.h"

/**
 * avl_insert - Inserts a value in an AVL Tree
 * @tree: Double pointer to the root node of theAVL tree for inserting thevalue
 * @value: Value to store in the node to be inserted
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *node, *z, *y, *x;

	node = bst_insert(tree, value);
	if (node == NULL)
		return (NULL);
	z = node->parent;
	while (z)
	{
		z->balance_factor = binary_tree_balance(z);
		if (z->balance_factor > 1 || z->balance_factor < -1)
		{
			y = (z->left) ? z->left : z->right;
			x = (y->left) ? y->left : y->right;
			if (z->balance_factor > 1 && y->balance_factor > 0)
				z = binary_tree_rotate_right(z);
			else if (z->balance_factor > 1 && y->balance_factor < 0)
			{
				binary_tree_rotate_left(y);
				z = binary_tree_rotate_right(z);
			}
			else if (z->balance_factor < -1 && y->balance_factor < 0)
				z = binary_tree_rotate_left(z);
			else if (z->balance_factor < -1 && y->balance_factor > 0)
			{
				binary_tree_rotate_right(y);
				z = binary_tree_rotate_left(z);
			}
			if (z && z->parent)
			{
				z->balance_factor = binary_tree_balance(z);
				z->parent->balance_factor = binary_tree_balance(z->parent);
			}
		}
		z = z->parent;
	}
	return (node);
}
