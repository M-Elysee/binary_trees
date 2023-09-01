#include "binary_trees.h"

int check_bst(const binary_tree_t *tree, int min, int max);
int check_balanced(const binary_tree_t *tree, int *height);
int abs_val(int n);
int get_max(int a, int b);

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: Pointer to root node of tree to check
 * Return: Returns 1 if tree is a valid AVL Tree otherwise returns 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int hght = 0;
	binary_tree_t *lft, *rght;

	if (!tree)
		return (0);

	lft = rght = (binary_tree_t *)tree;
	while (lft->left)
		lft = lft->left;
	while (rght->right)
		rght = rght->right;
	return (check_balanced(tree, &hght) && check_bst(tree, lft->n, rght->n));
}

/**
 * check_balanced - checks if binary tree is balanced
 * @tree: Pointer to root node of tree to check
 * @height: Height of tree
 * Return: Returns 1 if tree is balanced  otherwise 0
 */
int check_balanced(const binary_tree_t *tree, int *height)
{
	int r_hght = 0, l_hght = 0, lft, rght;

	if (!tree)
		return (1);

	lft = check_balanced(tree->left, &l_hght);
	rght = check_balanced(tree->right, &r_hght);

	if (abs_val(l_hght - r_hght) > 1)
		return (0);
	*height = get_max(l_hght, r_hght) + 1;
	return (lft && rght);
}

/**
 * check_bst - checks if a binary tree is valid Binary Search Tree
 * @tree: Pointer to root node of tree to check
 * @min: Minimum value
 * @max: Maximum value
 * Return: Returns 1 if tree is valid BST otherwisereturns 0
 */
int check_bst(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (check_bst(tree->left, min, tree->n - 1) &&
			check_bst(tree->right, tree->n + 1, max));
}

/**
 * get_max - returns the maximum of two integers
 * @a: First integer
 * @b: Second integer
 * Return: Returns maximum of a and b
 */
int get_max(int a, int b)
{
	return (a > b ? a : b);
}

/**
 * abs_val - returns absolute value of an integer
 * @n: Integer
 * Return: Returns absolute value of n
 */
int abs_val(int n)
{
	return (n < 0 ? -n : n);
}
