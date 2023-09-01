#include "binary_trees.h"

/**
 * binary_tree_is_heap - checks if binary tree is valid Max Binary Heap
 * @tree: Tree to check
 * Return: Returns 1 is it is orotherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int bal_val;

	if (tree == NULL)
	{
		return (0);
	}
	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n > tree->n)
	{
		return (0);
	}
	if (bt_is_perfect(tree))
		return (1);
	bal_val = bt_balance(tree);
	if (bal_val == 0)
	{
		return (bt_is_perfect(tree->left)
			&& binary_tree_is_heap(tree->right));
	}
	if (bal_val == 1)
	{
		return (binary_tree_is_heap(tree->left)
			&& bt_is_perfect(tree->right));
	}
	else
		return (0);
}

/**
 * tree_perfect - if a tree is perfect or not
 * @tree: Tree to check
 * Return: Returns 0 if not perfect or other number that is level of height
 */
int tree_perfect(const binary_tree_t *tree)
{
	int lft = 0, rgt = 0;

	if (tree->left && tree->right)
	{
		lft = 1 + tree_perfect(tree->left);
		rgt = 1 + tree_perfect(tree->right);
		if (rgt == lft && rgt != 0 && lft != 0)
			return (rgt);
		return (0);
	}
	else if (!tree->left && !tree->right)
		return (1);
	else
		return (0);
}

/**
 * bt_balance - Measures balance factor of binary tree
 * @tree: Tree to go through
 * Return: returns balanced factor
 */
int bt_balance(const binary_tree_t *tree)
{
	int rgt = 0, lft = 0, total = 0;

	if (tree)
	{
		lft = ((int)bt_height(tree->left));
		rgt = ((int)bt_height(tree->right));
		total = lft - rgt;
	}
	return (total);
}

/**
 * bt_is_perfect - perfect or not a tree
 * @tree: Tree to check
 * Return: returns 1 if it is or 0 otherwise
 */
int bt_is_perfect(const binary_tree_t *tree)
{
	int res = 0;

	if (tree == NULL)
		return (0);
	res = tree_perfect(tree);
	if (res != 0)
		return (1);
	return (0);
}

/**
 * bt_height - Measures height of binary tree
 * @tree: Tree to go through
 * Return: Returns height
 */
size_t bt_height(const binary_tree_t *tree)
{
	size_t lft = 0;
	size_t rgt = 0;

	if (tree == NULL)
	{
		return (0);
	}
	else
	{
		if (tree->left == NULL && tree->right == NULL)
			return (tree->parent != NULL);
		if (tree)
		{
			lft = tree->left ? 1 + bt_height(tree->left) : 0;
			rgt = tree->right ? 1 + bt_height(tree->right) : 0;
		}
		return ((lft > rgt) ? lft : rgt);
	}
}
