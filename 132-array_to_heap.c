#include "binary_trees.h"

/**
 * array_to_heap - builds a Max Binary Heap tree from array
 * @array: Input array
 * @size: Array size
 * Return: Return pointer to root node of created Binary Heap,
 * otherwise return NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	size_t x = 0;
	bst_t *rt = NULL;

	if (!array)
		return (NULL);
	while (x < size)
	{
		heap_insert(&rt, array[x]);
		x++;
	}
	return (rt);
}
