#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: Pointer to root node of tree to rotate.
 *
 * Return: Returns pointer to new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temp, *pvt;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	pvt = tree->right;
	temp = pvt->left;
	pvt->left = tree;
	tree->right = temp;
	if (temp != NULL)
		temp->parent = tree;
	temp = tree->parent;
	tree->parent = pvt;
	pvt->parent = temp;
	if (temp != NULL)
	{
		if (temp->left == tree)
			temp->left = pvt;
		else
			temp->right = pvt;
	}

	return (pvt);
}
