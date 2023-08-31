#include "binary_trees.h"
/**
* binary_trees_ancestor - find the closest common ancestor of 2 roots
* @first: is the root of the first tree
* @second: is the root of the second tree
* Return: a pointer to the closest ancestor on success
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *sec = second;


	while (first)
	{
		while (second)
		{
			if (first == second)
				return ((binary_tree_t *)first);
			second = second->parent;
		}
		first = first->parent;
		second = sec;
	}
	return (NULL);
}
