#include "binary_trees.h"
/**
* binary_tree_balance - it measures the balance factor of a tree
* @tree: points to the binary tree
* Return: the balance factor on success
*/
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left = 0, right = 0;

	if (tree == NULL)
		return (0);
	if (tree->left)
		left = binary_tree_height2(tree->left) + 1;
	if (tree->right)
		right = binary_tree_height2(tree->right) + 1;
	return (left - right);
}
/**
* binary_tree_height2 - a function that mesures the hight of a binary tree
* @tree: points to the root of the binary  tree
* Return: the height of a node or 0 on failure
*/
size_t binary_tree_height2(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	return (big(binary_tree_height2(tree->left),
				binary_tree_height2(tree->right)) + 1);
}
/**
* big - return the biggest value
* @value1: is the first value
* @value2: is the second value
* Return: the biggest value
*/
size_t big(size_t value1, size_t value2)
{
	if (value1 >= value2)
		return (value1);
	else
		return (value2);
}
