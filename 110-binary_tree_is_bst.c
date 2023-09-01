#include "binary_trees.h"

/**
 * is_bst - Compare node in order to check if given
 *
 * @tree: Pointer to root node of tree to check
 * @min: Minimum value
 * @max: Maximum value
 *
 * Return: Returns 1 if success, otherwise returns 0
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (
		is_bst(tree->left, min, tree->n - 1) &&
		is_bst(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search tree
 *
 * @tree: Pointer to root node of tree to check
 * Return: Returns 1 if success, otherwise returns 0
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst(tree, INT_MIN, INT_MAX));
}
