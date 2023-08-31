#include "binary_trees.h"
/**
* binary_tree_node - creates a binary node
* @parent: is the root on which the node is going to be attached
* @value: is the value to be conatined in the node
* Return: a pointer to the new node or null on failure
*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;


	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);
	new->left = NULL;
	new->right = NULL;
	new->n = value;
	new->parent = parent;
	return (new);
}
