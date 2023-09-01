#include <stdlib.h>
#include "binary_trees.h"

size_t get_count_node(const binary_tree_t *tree);
heap_t *ast_node(heap_t *root, size_t index, size_t size);
void td_heapify(heap_t *root);

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 *
 * Return: Returns value stored in root node otherwise return  0 on failure
 */
int heap_extract(heap_t **root)
{
	size_t sze;
	int val;
	heap_t *lst = NULL;

	if (!root || !*root)
		return (0);

	val = (*root)->n;
	sze = get_count_node(*root);
	lst = ast_node(*root, 0, sze);

	(*root)->n = lst->n;

	if (lst->parent)
	{
		if (lst->parent->left == lst)
			lst->parent->left = NULL;
		else
			lst->parent->right = NULL;
	}
	else
		*root = NULL;
	free(lst);
	td_heapify(*root);
	return (val);
}

/**
 * get_count_node - counts total number of nodes in binary tree
 * @tree: Pointer to root node of tree to count number of nodes
 * Return: Returns number of nodes in tree
 */
size_t get_count_node(const heap_t *tree)
{
	if (!tree)
		return (0);
	return (1 + get_count_node(tree->left) + get_count_node(tree->right));
}

/**
 * ast_node - Gets last node of a Max Binary Heap
 * @root: Pointer to root node of Heap
 * @index: Index of current node in binary representation of size
 * @size: Size of Heap
 *
 * Return: Return pointer to last node of Heap
 */
heap_t *ast_node(heap_t *root, size_t index, size_t size)
{
	heap_t *nd = root;

	if (!root || index >= size)
		return (NULL);
	if (index == size - 1)
		return (nd);
	nd = ast_node(root->left, 2 * index + 1, size);
	if (nd)
		return (nd);
	return (ast_node(root->right, 2 * index + 2, size));
}

/**
 * td_heapify - Moves node at top of tree down
 * @root: Pointer to root node of Heap
 * Return: Returns void
 */
void td_heapify(heap_t *root)
{
	heap_t *lrgst = root, *curr = NULL;
	int tmp;

	while (lrgst != curr)
	{
		curr = lrgst;
		if (curr->left && curr->left->n > curr->n)
			lrgst = curr->left;
		if (curr->right && curr->right->n > lrgst->n)
			lrgst = curr->right;
		tmp = curr->n;
		curr->n = lrgst->n;
		lrgst->n = tmp;
	}
}
