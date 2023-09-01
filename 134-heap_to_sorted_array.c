#include "binary_trees.h"
#include<stdlib.h>
/**
 * heap_to_sorted_array - converts Binary Max Heap to sorted array of integers
 *
 * @heap: pointer to root node of heap to convert
 * @size: address to store size of array
 * Return: Returns sorted array of integers
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int extrct, x = 0;
	int *arr;
	size_t hp_size;

	if (!heap)
		return (NULL);
	hp_size = binary_tree_size(heap);
	*size = hp_size;
	arr = malloc(hp_size * sizeof(int));
	if (!arr)
		return (NULL);
	while (heap)
	{
		extrct = heap_extract(&heap);
		arr[x] = extrct;
		x++;
	}
	return(arr);
}
