#include <stdlib.h>
#include "binary_trees.h"

avl_t *avl_rebal(avl_t *node);
avl_t *order_successor(avl_t *node);

/**
 * avl_remove - removes node from AVL tree
 * @root: pointer to root node of tree for removing node
 * @value: Value to remove in tree
 * Return: Pointer to root node of tree after removing
 * the desired value
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *tmp = NULL, *o_succ = NULL;

	if (!root)
		return (NULL);
	if (root->n > value)
		root->left = avl_remove(root->left, value);
	else if (root->n < value)
		root->right = avl_remove(root->right, value);
	else
	{
		if (!root->left || !root->right)
		{
			tmp = root->left ? root->left : root->right;
			if (tmp)
				tmp->parent = root->parent;
			free(root);
			return (avl_rebal(tmp));
		}
		else
		{
			o_succ = order_successor(root->right);
			root->n = o_succ->n;
			root->right = avl_remove(root->right, o_succ->n);
		}
	}
	return (avl_rebal(root));
}

/**
 * order_successor - finds inorder successor of a node
 * @node: Pointer to node
 * Return: Returns pointer to inorder successor node
 */
avl_t *order_successor(avl_t *node)
{
	avl_t *curr = node;

	while (curr && curr->left)
		curr = curr->left;
	return (curr);
}

/**
 * avl_rebal - rebalances AVL tree
 * @node: Pointer to node to rebalance
 * Return: Returns pointer to root node of tree after rebalancing
 */
avl_t *avl_rebal(avl_t *node)
{
	int bal_fact;

	if (!node)
		return (NULL);
	bal_fact = binary_tree_balance(node);
	if (bal_fact > 1)
	{
		if (binary_tree_balance(node->left) < 0)
			node->left = binary_tree_rotate_left(node->left);
		node = binary_tree_rotate_right(node);
	}
	else if (bal_fact < -1)
	{
		if (binary_tree_balance(node->right) > 0)
			node->right = binary_tree_rotate_right(node->right);
		node = binary_tree_rotate_left(node);
	}
	return (node);
}
