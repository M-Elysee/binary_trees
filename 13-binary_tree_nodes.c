#include "binary_trees.h"
/**
* binary_tree_nodes - provide the number of nodes with at least one child
* @tree: points to the root of the binary tree
* Return: number of nodes with 1 or 2 children
*/
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
	return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right) + 1);
}
