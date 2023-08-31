#include "binary_trees.h"
/**
* binary_tree_is_root - checks if a given argument is a root
* @node: points to a node to be identified if it's a root or not
* Return: 1 if it is a node otherwise 0
*/
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node && node->parent == NULL)
		return (1);
	return (0);
}
