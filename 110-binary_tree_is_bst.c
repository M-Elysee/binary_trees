#include "binary_trees.h"

/**
 * greater_thn - check if all values in tree are greater than value
 * @tree: Pointer to tree to check
 * @val: Value to check against
 *
 * Return: Returns 1 if true otherwise 0 if false
 */
int greater_thn(const binary_tree_t *tree, int val)
{
	int lft, rght;

	if (tree == NULL)
		return (1);
	if (tree->n > val)
	{
		lft = greater_thn(tree->left, val);
		rght = greater_thn(tree->right, val);
		if (lft && rght)
			return (1);
	}
	return (0);
}

/**
 * less_thn - check if all values in tree are less than a specific value
 * @tree: Pointer to tree to check
 * @val: Value to check against
 *
 * Return: Returns 1 if true otherwise returns 0 if false
 */
int less_thn(const binary_tree_t *tree, int val)
{
	int lft, rght;

	if (tree == NULL)
		return (1);
	if (tree->n < val)
	{
		lft = less_thn(tree->left, val);
		rght = less_thn(tree->right, val);
		if (lft && rght)
			return (1);
	}
	return (0);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid binary search tree
 * @tree: Pointer to root node of the tree to check
 *
 * Return: Returns 1 if tree is a valid BST, Othewise returns  0
 * If tree is NULL
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (less_thn(tree->left, tree->n) && greater_thn(tree->right, tree->n))
	{
		if (!tree->left || binary_tree_is_bst(tree->left))
		{
			if (!tree->right || binary_tree_is_bst(tree->right))
				return (1);
		}
	}
	return (0);
}
