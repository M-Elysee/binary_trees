#include "binary_trees.h"
/**
* binary_tree_insert_right - inserts a child at the right of a node parent
* @parent: points ti the node whose right side is going to be inserted
* @value: is the value contained on that new side
* Return: the new node or null on failure
*/
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new, *old_right;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL || parent == NULL)
		return (NULL);
	old_right = parent->right;
	new->right = old_right;
	new->left = NULL;
	new->parent = parent;
	new->n = value;
	parent->right = new;
	if (old_right)
		old_right->parent = new;
	return (new);
}
