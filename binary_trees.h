#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stdio.h>
#include <stdlib.h>

/**
* struct binary_tree_s - Binary tree node
* @n: Integer stored in the node
* @parent: Pointer to the parent node
* @left: Pointer to the left child node
* @right: Pointer to the right child node
*/
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;
typedef struct binary_tree_s heap_t;
typedef struct binary_tree_s bst_t;

/**
 * struct levelorder_queue_s - Level order traversal queue.
 * @node: A node of a binary tree.
 * @next: Next node to traverse to in binary tree.
 */
typedef struct levelorder_queue_s
{
	binary_tree_t *node;
	struct levelorder_queue_s *next;
} levelorder_queue_t;

void binary_tree_print(const binary_tree_t *);
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_height2(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
size_t big(size_t value1, size_t value2);
void display(const binary_tree_t *tree, size_t level, void (*func)(int));
int count_intnodes(binary_tree_t *root);
int is_itcomplete(binary_tree_t *root, int ind, int nd);
int binary_tree_is_complete(const binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
int is_bst(const binary_tree_t *tree, int min, int max);
int binary_tree_is_bst(const binary_tree_t *tree);
bst_t *bst_insert(bst_t **tree, int value);
bst_t *array_to_bst(int *array, size_t size);
bst_t *bst_search(const bst_t *tree, int value);
bst_t *find_min(bst_t *root);
bst_t *bst_remove(bst_t *root, int value);
int bt_balance(const binary_tree_t *tree);
int b_avl(const binary_tree_t *tree, int min, int max);
int b_t_l(const binary_tree_t *tree);
int binary_tree_is_avl(const binary_tree_t *tree);
void val_balancer(avl_t **root, avl_t *tree, int value);
avl_t *full_avl_insert(avl_t *tree, avl_t *parent, int value);
avl_t *avl_insert(avl_t **tree, int value);
avl_t *array_to_avl(int *array, size_t size);
int remove_type(bst_t *root);
int node_successor(bst_t *node);
bst_t *bst_remove(bst_t *root, int value);
void avl_bal(avl_t **tree);
avl_t *avl_remove(avl_t *root, int value);
avl_t *sorted_array_to_avl_revurse(int *array,
		int first_index, int final_index);
avl_t *sorted_array_to_avl(int *array, size_t size);
int tree_perfect(const binary_tree_t *tree);
int bt_balance(const binary_tree_t *tree);
int bt_is_perfect(const binary_tree_t *tree);
size_t bt_height(const binary_tree_t *tree);
int binary_tree_is_heap(const binary_tree_t *tree);
size_t b_t_s(const binary_tree_t *tree);
heap_t *heap_nfind(heap_t *root, size_t number);
heap_t *heap_insert(heap_t **tree, int value);
heap_t *array_to_heap(int *array, size_t size);
int heap_extract(heap_t **root);
int *heap_to_sorted_array(heap_t *heap, size_t *size);

bst_t *swap(bst_t *a, bst_t *b);
size_t binary_tree_sze(const binary_tree_t *tree);
heap_t *head_swap(heap_t *head, heap_t *node);
heap_t *perclate_down(heap_t *node);
int heap_extract(heap_t **root);

size_t bt_size(const binary_tree_t *tree);
int tree_is_complete(const binary_tree_t *tree, int i, int cnodes);
int bt_is_complete(const binary_tree_t *tree);
int parent_check(const binary_tree_t *tree);
int binary_tree_is_heap(const binary_tree_t *tree);


#endif
