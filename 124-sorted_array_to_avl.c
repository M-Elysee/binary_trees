#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 *
 * @array: Pointer to first element of array to be converted
 * @size: Number of element in array
 * Return: Returns pointer to root node of created AVL tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size < 1)
		return (NULL);
	return (sorted_array_to_avl_revurse(array, 0, size - 1));
}

/**
 * sorted_array_to_avl_revurse - recursive array to avl
 *
 * @array: Pointer to array
 * @first_index: The sub array initial index
 * @final_index: The sub array end index
 * Return: Returns pointer to root
 */
avl_t *sorted_array_to_avl_revurse(int *array, int first_index,
int final_index)
{
	int hlf;
	avl_t *rt;

	if (final_index < first_index)
		return (NULL);

	hlf = (final_index + first_index) / 2;
	rt = binary_tree_node(NULL, array[hlf]);
	if (!rt)
		return (NULL);
	rt->left = sorted_array_to_avl_revurse(array, first_index, hlf - 1);
	rt->right = sorted_array_to_avl_revurse(array, hlf + 1, final_index);
	if (rt->left)
		rt->left->parent = rt;
	if (rt->right)
		rt->right->parent = rt;
	return (rt);
}

