#include "binary_trees.h"
/**
* binary_tree_insert_left - inserts a child at the left side of a node parent
* @parent: points ti the node whose left side is going to be inserted
* @value: is the value contained on that new side
* Return: the new node or null on failure
*/
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new, *old_left;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL || parent == NULL)
		return (NULL);
	old_left = parent->left;
	new->left = old_left;
	new->right = NULL;
	new->parent = parent;
	new->n = value;
	parent->left = new;
	if (old_left)
		old_left->parent = new;
	return (new);
}
