#include "binary_tree.h"
/**
* binary_tree_levelorder -  it traverse a binary tree using level order
* @tree: points to the root of the tree
* @func: is the function to call on every node
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL)
		return (NULL);
	for (i = 0; tree; i++)
	{
		if (binary_tree_height(tree) == i)
			func(tree->n);
		tree = tree->left;
		tree = tree->right;
	}
