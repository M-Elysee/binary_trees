#include "binary_trees.h"

/**
 * heap_insert - heap inserter
 *
 * @tree: Double pointer to root
 * @value: Value to store
 * Return: Returns pointer to created node
 */
heap_t *heap_insert(heap_t **tree, int value)
{
	int do_swap = 1;
	size_t sze;
	heap_t *new_n, *prnt;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		new_n = binary_tree_node(NULL, value);
		*tree = new_n;
		return (new_n);
	}

	sze = b_t_s(*tree);
	prnt = heap_nfind(*tree, (sze - 1) / 2);
	new_n = binary_tree_node(prnt, value);
	if (sze % 2 == 1)
		prnt->left = new_n;
	else
		prnt->right = new_n;
	if (new_n == NULL)
		return (NULL);

	while (do_swap == 1 && prnt != NULL)
	{
		if (prnt->n >= new_n->n)
			do_swap = 0;
		else
		{
			new_n = heap_rebal(new_n, prnt);
			prnt = new_n->parent;
		}
	}

	return (new_n);
}

/**
 * heap_rebal - heap rebalancer
 * @new: Pointer to new node
 * @parent: Pointer to new parent
 * Return: Returns parent
 */
heap_t *heap_rebal(heap_t *new, heap_t *parent)
{
	int n_temp;

	n_temp = new->n;
	new->n = parent->n;
	parent->n = n_temp;
	return (parent);
}

/**
 * bts - measure tree
 *
 * @tree: Pointer to root
 * Return: Returns size, otherwise returns 0
 */
size_t b_t_s(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + b_t_s(tree->left) + b_t_s(tree->right));
}

/**
 * heap_nfind - heap node finder
 *
 * @root: Pointer to root
 * @number: Index of node to find
 * Return: Pointer to node
 */
heap_t *heap_nfind(heap_t *root, size_t number)
{
	size_t prnt_n, dr;

	if (number == 0)
		return (root);

	prnt_n = (number - 1) / 2;
	dr = (number - 1) % 2;

	if (dr == 0)
		return (heap_nfind(root, prnt_n)->left);
	return (heap_nfind(root, prnt_n)->right);
}
