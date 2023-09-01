#include "binary_trees.h"

/**
 * find_min - Finds min root
 * @root: Pointer to tree
 * Return: Returns min number
 */
bst_t *find_min(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 *
 * @root: Pointer to root node of tree where you will remove a node
 * @value: Value to remove in tree
 * Return: Returns pointer to new root node of the tree
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *prnt, *tmp;

	if (root == NULL)
		return (NULL);
	else if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->left == NULL)
		{
			tmp = root;
			prnt = root->parent;
			root = root->right;
			root->parent = prnt;
			free(tmp);
		}
		else if (root->right == NULL)
		{
			tmp = root;
			prnt = root->parent;
			root = root->left;
			root->parent = prnt;
			free(tmp);
		}
		else
		{
			tmp = find_min(root->right);
			root->n = tmp->n;
			root->right = bst_remove(root->right, tmp->n);
		}
	}
	return (root);
}
