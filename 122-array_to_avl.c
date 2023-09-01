#include "binary_trees.h"

/**
 * array_to_avl - Builds an AVL tree from array.
 * @array: Pointer to first element of array to be converted.
 * @size: Number of elements in @array.
 *
 * Return: Returna pointer to root node of created AVL, or NULL upon failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tr = NULL;
	size_t x, y;

	if (array == NULL)
		return (NULL);

	for (x = 0; x < size; x++)
	{
		for (y = 0; y < x; y++)
		{
			if (array[y] == array[x])
				break;
		}
		if (y == x)
		{
			if (avl_insert(&tr, array[x]) == NULL)
				return (NULL);
		}
	}

	return (tr);
}
