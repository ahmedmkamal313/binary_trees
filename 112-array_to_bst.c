#include "binary_trees.h"

/**
 * array_to_bst - Builds a Binary Search Tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of element in the array
 * Return: Pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree;
	size_t i;

	/* Check if array is NULL or size is zero */
	if (array == NULL || size == 0)
		return (NULL);

	/* Initialize tree as NULL */
	tree = NULL;

	/* Loop through each element of the array */
	for (i = 0; i < size; i++)
	{
		/* Insert the element in the BST using bst_insert function */
		bst_insert(&tree, array[i]);
	}

	/* Return the root node of the BST */
	return (tree);
}
