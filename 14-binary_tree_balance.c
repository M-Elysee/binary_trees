#include "binary_trees.h"
/**
* binary_tree_balance - it measures the balance factor of a tree
* @tree: points to the binary tree
* Return: the balance factor on success
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (-1);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	return (binary_tree_balance(tree->left) - binary_tree_balance(tree->right));
}
