#include "binary_trees.h"
#include <stdlib.h>

/**
 * bt_size - measures size of a binary tree
 *
 * @tree: tree root
 * Return: Returns size of tree or 0 if tree is NULL;
 */
size_t bt_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (bt_size(tree->left) + bt_size(tree->right) + 1);
}

/**
 * tree_is_complete - checks if tree is complete
 *
 * @tree: Pointer to tree root
 * @i: Node index
 * @cnodes: Number of nodes
 * Return: Returns 1 if tree is complete otherwise returns 0
 */
int tree_is_complete(const binary_tree_t *tree, int i, int cnodes)
{
	if (tree == NULL)
		return (1);

	if (i >= cnodes)
		return (0);

	return (tree_is_complete(tree->left, (2 * i) + 1, cnodes) &&
		tree_is_complete(tree->right, (2 * i) + 2, cnodes));
}

/**
 * bt_is_complete - calls to tree_is_complete function
 *
 * @tree: tree root
 * Return: Returns 1 if tree is complete otherwise returns 0
 */
int bt_is_complete(const binary_tree_t *tree)
{
	size_t c_nodes;

	if (tree == NULL)
		return (0);

	c_nodes = bt_size(tree);

	return (tree_is_complete(tree, 0, c_nodes));
}

/**
 * parent_check - checks if parent has a greater value than its childs
 *
 * @tree: Pointer to node
 * Return: Returns 1 if parent has a greater value otherwise 0
 */
int parent_check(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (1);

	if (tree->n > tree->parent->n)
		return (0);

	return (parent_check(tree->left) && parent_check(tree->right));
}

/**
 * binary_tree_is_heap - checks if input tree is Max Binary Heap
 *
 * @tree: Pointer to root of the tree
 * Return: Returns 1 if tree is Max Binary Heap otherwise returns 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!bt_is_complete(tree))
		return (0);

	return (parent_check(tree->left) && parent_check(tree->right));
}
