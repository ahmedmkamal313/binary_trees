#include "binary_trees.h"

/**
 * binary_tree_levelorder - Goes through binary treeusing level-order traversal
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t **queue;
	size_t front, back;

	/* Check if tree or func is NULL */
	if (tree == NULL || func == NULL)
		return;
	/* Allocate memory for the queue */
	queue = malloc(sizeof(*queue));
	if (queue == NULL)
		return;
	/* Initialize the front and back indices of the queue */
	front = 0;
	back = 0;
	/* Enqueue the root node */
	queue[back++] = tree;
	/* Loop until the queue is empty */
	while (front < back)
	{
		tree = queue[front++];
		func(tree->n);
		/* Enqueue the left child if it exists */
		if (tree->left != NULL)
		{
			/* Reallocate memory for the queue if needed */
			queue = realloc(queue, sizeof(*queue) * (back + 1));
			if (queue == NULL)
				return;
			queue[back++] = tree->left;
		}
		/* Enqueue the right child if it exists */
		if (tree->right != NULL)
		{
			/* Reallocate memory for the queue if needed */
			queue = realloc(queue, sizeof(*queue) * (back + 1));
			if (queue == NULL)
				return;
			queue[back++] = tree->right;
		}
	}
	free(queue);
}
