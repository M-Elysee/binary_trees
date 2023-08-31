#include "binary_trees.h"
/**
* binary_tree_depth - finds the depth of a node in a binary tree
* @tree: points to the node bo be studied
* Return: the level of the node on success or 0 on failure
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL && tree->parent == NULL)
		return (0);
	return (binary_tree_depth(tree->parent) + 1);
}
