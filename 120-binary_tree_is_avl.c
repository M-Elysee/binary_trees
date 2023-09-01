#include "binary_trees.h"

/**
 * binary_tree_is_avl - checks if binary tree is valid AVL Tree
 * @tree: Pointer to root node of tree to check
 *
 * Return: Returns 1 if tree is valid AVL Tree otherwise returns  0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (b_avl(tree, INT_MIN, INT_MAX));
}

/**
 * bt_balance - the factor calculate
 *
 * @tree: Pointer to root
 * Return: Returns a integer with factor
 */
int bt_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (b_t_l(tree->left) - b_t_l(tree->right));
}

/**
 * b_avl - Checks level
 *
 * @tree: Pointer to root
 * @min: Min value
 * @max: Max value
 * Return: Returns 1 if is AVL, otherwise returns 0
 */
int b_avl(const binary_tree_t *tree, int min, int max)
{
	int bal_left, bal_right, bal;

	if (tree == NULL)
	{
		return (1);
	}
	if (tree->n > max || tree->n < min)
		return (0);
	bal = bt_balance(tree);
	if (bal < -1 || bal > 1)
	{
		return (0);
	}
	bal_left = b_avl(tree->left, min, tree->n - 1);
	bal_right = b_avl(tree->right, tree->n + 1, max);
	if (bal_left == 1 && bal_right == 1)
		return (1);
	return (0);
}

/**
 * b_t_l - auxiliary level
 *
 * @tree: Pointer to root
 * Return: Return an integer with level
 */
int b_t_l(const binary_tree_t *tree)
{
	int h_lft, h_rgt;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	h_lft = b_t_l(tree->left);
	h_rgt = b_t_l(tree->right);
	if (h_lft > h_rgt)
		return (h_lft + 1);
	else
		return (h_rgt + 1);
}
