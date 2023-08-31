#include "binary_trees.h"
/**
* binary_tree_is_full - checks if a tree is full
* @tree: points to the root of the tree
* Return: 1 if it is full and 0 otherwise
*/
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
}
