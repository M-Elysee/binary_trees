#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: Double pointer to root node of the BST to insert value.
 * @value: Value to store in node to be inserted.
 *
 * Return: Returns pointer to created node, or returns NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *crrnt, *new;

	if (tree != NULL)
	{
		crrnt = *tree;

		if (crrnt == NULL)
		{
			new = binary_tree_node(crrnt, value);
			if (new == NULL)
				return (NULL);
			return (*tree = new);
		}

		if (value < crrnt->n)
		{
			if (crrnt->left != NULL)
				return (bst_insert(&crrnt->left, value));

			new = binary_tree_node(crrnt, value);
			if (new == NULL)
				return (NULL);
			return (crrnt->left = new);
		}
		if (value > crrnt->n)
		{
			if (crrnt->right != NULL)
				return (bst_insert(&crrnt->right, value));

			new = binary_tree_node(crrnt, value);
			if (new == NULL)
				return (NULL);
			return (crrnt->right = new);
		}
	}
	return (NULL);
}
