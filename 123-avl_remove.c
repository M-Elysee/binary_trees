#include "binary_trees.h"

/**
 * avl_remove - remove node from AVL tree
 * @root: The root of tree
 * @value: Node with value to remove
 * Return: Returns tree changed
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_val = (avl_t *)bst_remove((bst_t *)root, value);

	if (root_val == NULL)
		return (NULL);
	avl_bal(&root_val);
	return (root_val);
}
/**
 *remove_type - function that removes node depending of its children
 *@root: The node to remove
 *Return: returns 0 if it has no children or other value
 */
int remove_type(bst_t *root)
{
	int n_val = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
			{
				root->parent->right = root->left;
			}
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}

		free(root);
		return (0);
	}
	n_val = successor(root->right);
	root->n = n_val;
	return (n_val);
}

/**
 * node_successor - Get next successor i mean min node in right subtree
 * @node: The tree to check
 * Return: Returns min value of this tree
 */
int node_successor(bst_t *node)
{
	int lft = 0;

	if (node == NULL)
		return (0);
	lft = node_successor(node->left);
	if (lft == 0)
		return (node->n);
	return (lft);
}

/**
 * bst_remove - remove node from BST tree
 * @root: The root of tree
 * @value: Node with value to remove
 * Return: Returns tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int typ = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		typ = remove_type(root);
		if (typ != 0)
			bst_remove(root->right, typ);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_bal - measures a balance factor of a AVL
 * @tree: Tree to go through
 * Return: returns balanced factor
 */
void avl_bal(avl_t **tree)
{
	int b_val;

	if (tree == NULL || *tree == NULL)
		return;

	if ((*tree)->left == NULL && (*tree)->right == NULL)
		return;

	avl_bal(&(*tree)->left);
	avl_bal(&(*tree)->right);
	b_val = binary_tree_balance((const binary_tree_t *)*tree);
	if (b_val > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (b_val < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
