#include "binary_trees.h"
#include <stdlib.h>

#define CONV "0123456789ABCDEF"

#define INITIALIZE_NODE {0, NULL, NULL, NULL}


#define FREE_NODE_BLOC { \
		res = tmp->n; \
		free(tmp); \
		*root = NULL; \
	}

#define SET_NODE_BLOC { \
	tmp = *root; \
	size = binary_tree_size(*root); \
	binary = &buffer[49]; \
	*binary = 0; \
	}

#define CONVT_LOOP { \
		*--binary = CONV[size % 2]; \
		size /= 2; \
	}

#define head_swap_bloc { \
		head = *root; \
		head = head_swap(head, tmp); \
		res = head->n; \
		free(head); \
		*root = tmp; \
		tmp = perclate_down(tmp); \
		*root = tmp; \
	}

/**
 * swap - swaps two nodes in binary tree
 * @a: The first node
 * @b: The second node
 * Return: Returns pointer to root
 */
bst_t *swap(bst_t *a, bst_t *b)
{
	bst_t a_cp = INITIALIZE_NODE;

	a_cp.n = a->n;
	a_cp.parent = a->parent;
	a_cp.left = a->left;
	a_cp.right = a->right;
	a->parent = b;
	a->left = b->left;
	a->right = b->right;
	if (b->left) {
		b->left->parent = a;
    }
    if (b->right) {
		b->right->parent = a;
    }
    b->parent = a_cp.parent;
	if (a_cp.parent)
	{
		if (a == a_cp.parent->left)
			a_cp.parent->left = b;
		else
			a_cp.parent->right = b;
	}
	if (b == a_cp.left)
	{
		b->left = a;
		b->right = a_cp.right;
		if (a_cp.right)
			a_cp.right->parent = b;
	}
	else if (b == a_cp.right)
	{
		b->right = a;
		b->left = a_cp.left;
		if (a_cp.left)
			a_cp.left->parent = b;
	}
	while (b->parent) {
		b = b->parent;
    }
    return (b);
}

/**
 * binary_tree_size - measures size of binary tree
 * @tree: input binary tree
 * Return: Returns number of descendant child nodes
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return(0);

	return(1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * head_swap - helper function to swap head and node
 * @head: Pointer to head
 * @node: pointer to node
 * Return: Returns pointer to severed head of tree
 */
heap_t *head_swap(heap_t *head, heap_t *node)
{
	if (node->parent->left == node) {
		node->parent->left = NULL;
	} else {
		node->parent->right = NULL;
    }
	node->parent = NULL;
	node->left = head->left;
	node->right = head->right;
	if (head->left)
		head->left->parent = node;
	if (head->right)
		head->right->parent = node;
	return (head);
}

/**
 * perclate_down - percolate head into correct position
 * @node: Pointer to head
 * Return: Returns pointer to head of tree
 */
heap_t *perclate_down(heap_t *node)
{
	heap_t *nxt = node;
	int maximum;

	if (!node)
		return (NULL);
	maximum = node->n;
	if (node->left)
		maximum = MAX(node->left->n, maximum);
	if (node->right)
		maximum = MAX(node->right->n, maximum);
	if (node->left && maximum == node->left->n)
		nxt = node->left;
	else if (node->right && maximum == node->right->n)
		nxt = node->right;
	if (nxt != node)
	{
		swap(node, nxt);
		perclate_down(node);
	}
	return (nxt);
}

/**
 * heap_extract - extracts root node of Max Binary Heap
 * @root: Double pointer to root of tree
 * Return: Return value stored in root node
 */
int heap_extract(heap_t **root)
{
    int res;
    char buffer[50], *binary, y;
	heap_t *head, *tmp;
	size_t size, x;

	if (!root || !*root)
		return (0);
	SET_NODE_BLOC;
	if (size == 1) {
		FREE_NODE_BLOC;
		return (res);
	}
	do {
		CONVT_LOOP;
	} while (size);

	for (x = 1; x < strlen(binary); x++)
	{
		y = binary[x];
		if (x == strlen(binary) - 1)
		{
			if (y == '1'){
				tmp = tmp->right;
				break;
			}
			else if (y == '0'){
				tmp = tmp->left;
				break;
			}
		}
		if (y == '1')
			tmp = tmp->right;
		else if (y == '0')
			tmp = tmp->left;
	}
	head_swap_bloc;
	return (res);
}
