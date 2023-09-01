#include "binary_trees.h"

int get_nodes_total(const binary_tree_t *tree);
int check_b_heap(const binary_tree_t *tree, int index,
			  int max_index, int max_val);

/**
 * binary_tree_is_heap - Checks if binary tree is valid Max Binary Heap
 * @tree: Pointer to root node of tree to check
 *
 * Return: Returns 1 if tree is valid Max Binary Heap otherwise returns 0
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int nd;

	if (!tree)
		return (0);
	nd = get_nodes_total(tree);
	return (check_b_heap(tree, 0, nd - 1, tree->n));
}

/**
 * get_nodes_total - Counts total number of nodes in binary tree
 * @tree: Pointer to root node of tree to count number of nodes
 *
 * Return: Returns total number of nodes in tree
 */
int get_nodes_total(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + get_nodes_total(tree->left) + get_nodes_total(tree->right));
}

/**
 * check_b_heap - Checks if  binary tree is valid Max Binary Heap
 *
 * @tree: Pointer to root node of tree to check
 * @index: Index of current node
 * @max_index: Max index of tree
 * @max_val: Max value of tree
 *
 * Return: Returns 1 if tree is valid Max Binary Heap otherwise returns
 */
int check_b_heap(const binary_tree_t *tree, int index,
			  int max_index, int max_val)
{
	if (!tree)
		return (1);
	if (index > max_index || tree->n > max_val)
		return (0);
	return (check_b_heap(tree->left, 2 * index + 1, max_index, tree->n) &&
			check_b_heap(tree->right, 2 * index + 2, max_index, tree->n));
}
