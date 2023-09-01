#include "binary_trees.h"

/**
 * avl_insert - Inserts value in avl
 *
 * @tree: Double pointer to root
 * @value: Value
 * Return: Returns Pointer to new node
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_nd, *predec;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		new_nd = binary_tree_node(NULL, value);
		*tree = new_nd;
		return (new_nd);
	}
	new_nd = full_avl_insert(*tree, NULL, value);

	if (new_nd == NULL)
		return (NULL);

	predec = new_nd->parent;

	while (predec != NULL)
	{
		val_balancer(tree, predec, value);
		predec = predec->parent;
	}

	return (new_nd);
}

/**
 * val_balancer - rebalance AVL tree if needed
 *
 * @root: Pointer to root of tree
 * @tree: Pointer to node to be rebalanced
 * @value: Inserted value
 * Return: returns 0
 */
void val_balancer(avl_t **root, avl_t *tree, int value)
{
	int new_bal;

	new_bal = binary_tree_balance(tree);
	if (new_bal > 1)
	{
		if (tree->left->n > value)
		{
			if (*root == tree)
				*root = tree->left;
			binary_tree_rotate_right(tree);
		}
		else
		{
			if (*root == tree)
				*root = tree->left->right;
			binary_tree_rotate_left(tree->left);
			binary_tree_rotate_right(tree);
		}
	}
	if (new_bal < -1)
	{
		if (tree->right->n < value)
		{
			if (*root == tree)
			{
				*root = tree->right;
			}
			binary_tree_rotate_left(tree);
		}
		else
		{
			if (*root == tree)
			{
				*root = tree->right->left;
			}
			binary_tree_rotate_right(tree->right);
			binary_tree_rotate_left(tree);
		}
	}
}

/**
 * full_avl_insert - Inserts a value
 *
 * @tree: Pointer to root
 * @parent: Parent of node
 * @value: Value
 * Return: Returns a pointer to new_node node
 */
avl_t *full_avl_insert(avl_t *tree, avl_t *parent, int value)
{
	avl_t *new_nd;

	if (tree == NULL)
	{
		new_nd = binary_tree_node(parent, value);
		if (parent->n > new_nd->n)
			parent->left = new_nd;
		else
			parent->right = new_nd;
		return (new_nd);
	}
	else if (value == tree->n)
	{
		return (NULL);
	}
	else if (value < tree->n)
	{
		return (full_avl_insert(tree->left, tree, value));
	}
	else
	{
		return (full_avl_insert(tree->right, tree, value));
	}
}
