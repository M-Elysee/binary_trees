#include "binary_trees.h"
/**
* binary_tree_size - find the size of a binary tree
* @tree: points to the root of the binary tree
* Return: the number of node in the tree on success
*/
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
