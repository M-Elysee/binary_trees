#include <stdlib.h>
#include "binary_trees.h"

/**
 * heap_to_sorted_array - Converts Binary Max Heap to sorted array of
 * integers
 *
 * @heap: Pointer to root node of heap to convert
 * @size: Address to store size of array
 *
 * Return: returns pointer to a newly allocated array containing sorted values,
 * otherwise returns NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int *arry = NULL;

	*size = 0;
	if (!heap)
		return (NULL);

	arry = calloc(1, sizeof(int));
	if (!arry)
		return (NULL);

	while (heap)
	{
		arry = realloc(arry, sizeof(int) * (*size + 1));
		arry[*size] = heap_extract(&heap);
		*size += 1;
	}
	return (arry);
}
