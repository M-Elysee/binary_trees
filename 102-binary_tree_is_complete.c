#include "binary_trees.h"


/**
 * binary_tree_is_complete - check for bt complete
 * @tree: Pointer to root
 *
 * Return: 1 if
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	binary_tree_t *root;
	int nd;

	if (!tree)
		return (0);

	root = (binary_tree_t *)tree;
	nd = count_nodes(root);

	return (is_complete(root, 0, nd));
}

/**
 * count_intnodes - Counts ths inside tree
 * @root: node
 *
 * Return: Number of nodes
 */
int count_intnodes(binary_tree_t *root)
{
	if (!root)
		return (0);

	return (1 + count_nodes(root->left) + count_nodes(root->right));
}

/**
 * is_complete - Check if tree is complete
 * @root: Pointer to tree's root
 * @index: Index of node been evaluated
 * @n: number of trees nodes
 *
 * Return: Returns 1 if tree is a heap, otherwise returns 0
 */
int is_itcomplete(binary_tree_t *root, int ind, int nd)
{
	if (!root)
		return (0);
	if (ind >= nd)
		return (0);
	if (!root->left && !root->right)
		return (1);
	if (root->right && !root->left)
		return (0);
	if (root->left && !root->right)
		return (is_complete(root->left, ind * 2 + 1, nd));

	return (is_complete(root->left, ind * 2 + 1, nd) &&
			is_complete(root->right, ind * 2 + 2, nd));
}
