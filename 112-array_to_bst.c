#include "binary_trees.h"
/**
 * array_to_bst - Turns an array to a BST tree
 * @array: Array to turns to BST tree
 * @size: Size of array
 * Return: returns BST tree from array
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root;
	size_t y = 0;

	root = NULL;
	if (size == 0)
		return (NULL);
	for (; y < size; y++)
	{
		if (y == 0)
			bst_insert(&root, array[y]);
		else
			bst_insert(&root, array[y]);
	}
	return (root);
}
