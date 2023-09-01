#include "binary_trees.h"
/**
* binary_tree_levelorder -  it traverse a binary tree using level order
* @tree: points to the root of the tree
* @func: is the function to call on every node
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t num_levels, i;

	if (tree == NULL || func == NULL)
		return;
	num_levels = binary_tree_height(tree);
	for (i = 0; i <= num_levels; i++)
		display(tree, i, func);
}
/**
* display - traverse levels by level in a binary tree
* @tree: points to the root of the tree
* @level: is the level to be accessed
* @fun: is the function tobe call on every node accessed
*/
void display(const binary_tree_t *tree, size_t level, void (*func)(int))
{
	if (tree == NULL)
		return;
	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		display(tree->left, level - 1, func);
		display(tree->right, level - 1, func);
	}
}
/**
* binary_tree_height - a function that mesures the hight of a binary tree
* @tree: points to the root of the binary  tree
* Return: the height of a node or 0 on failure
*/
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	return (big(binary_tree_height(tree->left),
				binary_tree_height(tree->right)) + 1);
}
/**
* big - return the biggest value
* @value1: is the first value
* @value2: is the second value
* Return: the biggest value
*/
size_t big(size_t value1, size_t value2)
{
	if (value1 > value2)
		return (value1);
	else
		return (value2);
}
