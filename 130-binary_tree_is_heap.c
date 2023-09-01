#include "binary_trees.h"

/**
 * binary_tree_is_heap - checks if a binary tree is a valid Max Binary Heap
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap
 *         0 if tree is NULL
 *         0 otherwise
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (btih_h(tree));
}

/**
 * btih_h - checks if a binary tree is a valid Max Binary Heap
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid Max Binary Heap
 *         1 if tree is NULL
 *         0 otherwise
 */
int btih_h(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (!bt_is_complete(tree))
		return (0);

	if (tree->left)
		if (tree->left->n > tree->n)
			return (0);
	if (tree->right)
		if (tree->right->n > tree->n)
			return (0);

	return (btih_h(tree->left) &&
		btih_h(tree->right));
}

/**
 * bt_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete
 *         0 if the tree is not complete
 *         0 if tree is NULL
 */
int bt_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (!tree)
		return (0);
	size = bt_size(tree);

	return (btic_h(tree, 0, size));
}

/**
 * btic_h - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to check
 * @index: node index to check
 * @size: number of nodes in the tree
 *
 * Return: 1 if the tree is complete
 *         0 if the tree is not complete
 *         0 if tree is NULL
 */
int btic_h(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (btic_h(tree->left, 2 * index + 1, size) &&
		btic_h(tree->right, 2 * index + 2, size));
}

/**
 * bt_size - measures the size of a binary tree
 * @tree: tree to measure the size of
 *
 * Return: size of the tree
 *         0 if tree is NULL
 */
size_t bt_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (bt_size(tree->left) +
		bt_size(tree->right) + 1);
}
