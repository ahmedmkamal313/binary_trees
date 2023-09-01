#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of element in the array
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree, **queue, *node;
	size_t i, j, front, rear;

	if (array == NULL || size == 0)
		return (NULL);
	qsort(array, size, sizeof(int), cmpfunc);
	for (i = 0, j = 1; j < size; j++)
	{
		if (array[i] != array[j])
			array[++i] = array[j];
	}
	size = i + 1;
	queue = malloc(sizeof(avl_t *) * size);
	if (queue == NULL)
		return (NULL);
	/* Create root node and enqueue it */
	tree = binary_tree_node(NULL, 0);
	if (tree == NULL)
	{
		free(queue);
		return (NULL);
	}
	queue[0] = tree;
	front = 0;
	rear = 1;
	while (rear < size)
	{
		/* Dequeue a node and assign it left and right children */
		node = queue[front++];
		node->left = binary_tree_node(node, 0);
		node->right = binary_tree_node(node, 0);
		/* Enqueue the children */
		queue[rear++] = node->left;
		queue[rear++] = node->right;
	}
	i = 0;
	assign_values(tree, array, &i);
	/* Free the queue and return the tree */
	free(queue);
	return (tree);
}

/**
 * cmpfunc - Compares two integers for qsort
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 * Return: The difference between a and b
 */
int cmpfunc(const void *a, const void *b)
{
	return (*(int *)a - *(int *)b);
}

/**
 * assign_values - Assigns values from an array to a tree in inorder
 * @tree: Pointer to the root node of the tree
 * @array: Pointer to the first element of the array
 * @index: Pointer to the current index of the array
 */
void assign_values(avl_t *tree, int *array, size_t *index)
{
	if (tree == NULL)
		return;

	/* Assign values to left subtree */
	assign_values(tree->left, array, index);

	/* Assign value to current node */
	tree->n = array[*index];
	(*index)++;
	/* Assign values to right subtree */
	assign_values(tree->right, array, index);
}
