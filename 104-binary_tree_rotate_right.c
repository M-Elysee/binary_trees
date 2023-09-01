#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Right-rotates a binary tree.
 * @tree: Pointer to root node of tree to rotate.
 *
 * Return: Returns pointer to new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pvt, *temp;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	pvt = tree->left;
	temp = pvt->right;
	pvt->right = tree;
	tree->left = temp;
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
