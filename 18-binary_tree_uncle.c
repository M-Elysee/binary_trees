#include "binary_trees.h"
/**
* binary_tree_uncle - find the uncle of a node
* @node: points to the root of a binary tree
* Return: a pointer to the uncle or null on failure
*/
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent || !(node->parent)->parent)
		return (NULL);
	if (((node->parent)->parent)->left == node->parent)
		return (((node->parent)->parent)->right);
	return (((node->parent)->parent)->left);
}
