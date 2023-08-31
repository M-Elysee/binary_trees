#include "binary_trees.h"
/**
* binary_tree_sibling - a finds the sibling of a node
* @node: points to the root of the binary tree
* Return: the node or null on failure
*/
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node ==  NULL || node->parent == NULL)
		return (NULL);
	if ((node->parent)->left == node)
		return ((node->parent)->right);
	return ((node->parent)->left);
}
