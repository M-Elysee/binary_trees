#include "binary_trees.h"

levelorder_queue_t *create_node(binary_tree_t *node);
int binary_tree_is_complete(const binary_tree_t *tree);
void push(binary_tree_t *node, levelorder_queue_t *head,
		  levelorder_queue_t **tail);
void free_queue(levelorder_queue_t *head);
void pop(levelorder_queue_t **head);

/**
 * pop - Pops head of a levelorder_queue_t queue.
 * @head: Double pointer to the head of queue.
 */
void pop(levelorder_queue_t **head)
{
	levelorder_queue_t *tm;

	tm = (*head)->next;
	free(*head);
	*head = tm;
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to traverse.
 *
 * Return: Returns Null if  tree is NULL or not complete, 0.
 *         Otherwise 1.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	levelorder_queue_t *hd, *tl;
	unsigned char flag = 0;

	if (tree == NULL)
		return (0);

	hd = tl = create_node((binary_tree_t *)tree);
	if (hd == NULL)
		exit(1);

	while (hd != NULL)
	{
		if (hd->node->left != NULL)
		{
			if (flag == 1)
			{
				free_queue(hd);
				return (0);
			}
			push(hd->node->left, hd, &tl);
		}
		else
			flag = 1;
		if (hd->node->right != NULL)
		{
			if (flag == 1)
			{
				free_queue(hd);
				return (0);
			}
			push(hd->node->right, hd, &tl);
		}
		else
			flag = 1;
		pop(&hd);
	}
	return (1);
}


/**
 * push - Pushes a node to back of a levelorder_queue_t queue.
 * @node: Binary tree node to print and push.
 * @head: Double pointer to  head of queue.
 * @tail: Double pointer to tail of queue.
 *
 * Return: Upon malloc failure, exits with a status code of 1.
 */
void push(binary_tree_t *node, levelorder_queue_t *head,
		  levelorder_queue_t **tail)
{
	levelorder_queue_t *n_node;

	n_node = create_node(node);
	if (n_node == NULL)
	{
		free_queue(head);
		exit(1);
	}
	(*tail)->next = n_node;
	*tail = n_node;
}


/**
 * create_node - Creates new node.
 * @node: Binary tree node for  new node to contain.
 *
 * Return: returns null if error occurs.
 *         Otherwise returns  pointer to new node.
 */
levelorder_queue_t *create_node(binary_tree_t *node)
{
	levelorder_queue_t *n_node;

	n_node = malloc(sizeof(levelorder_queue_t));
	if (n_node == NULL)
		return (NULL);

	n_node->node = node;
	n_node->next = NULL;

	return (n_node);
}

/**
 * free_queue - Frees a levelorder_queue_t queue.
 * @head: Pointer to head of the queue.
 */
void free_queue(levelorder_queue_t *head)
{
	levelorder_queue_t *tm;

	while (head != NULL)
	{
		tm = head->next;
		free(head);
		head = tm;
	}
}
