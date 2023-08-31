#include "binary_trees.h"
/**
* binary_tree_preorder - this functions traverse the binary tree using preoder
* @tree: points to the root of the tree
* @func: points to a function to call on each node
*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;
	func(tree->n);
	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
