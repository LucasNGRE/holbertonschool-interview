#include "binary_trees.h"

/**
 * tree_size - counts the number of nodes in a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: number of nodes, 0 if tree is NULL
 */
static size_t tree_size(const heap_t *tree)
{
	if (!tree)
		return (0);
	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * find_parent - finds the parent of the next node to insert, using the
 *               binary representation of the insertion index to navigate
 * @root: pointer to the root node of the heap
 * @idx: 1-indexed level-order position of the node to be inserted
 *
 * Return: pointer to the parent node of the position to insert
 */
static heap_t *find_parent(heap_t *root, size_t idx)
{
	size_t mask;

	mask = 1;
	while ((mask << 1) <= idx)
		mask <<= 1;
	mask >>= 1;
	while (mask > 1)
	{
		if (idx & mask)
			root = root->right;
		else
			root = root->left;
		mask >>= 1;
	}
	return (root);
}

/**
 * sift_up - restores the Max Heap property by swapping the node's value
 *           with its parent's while it is greater than its parent
 * @node: pointer to the freshly inserted node
 *
 * Return: pointer to the node holding the inserted value after sifting
 */
static heap_t *sift_up(heap_t *node)
{
	int tmp;

	while (node->parent && node->n > node->parent->n)
	{
		tmp = node->n;
		node->n = node->parent->n;
		node->parent->n = tmp;
		node = node->parent;
	}
	return (node);
}

/**
 * heap_insert - inserts a value into a Max Binary Heap
 * @root: double pointer to the root node of the Heap
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *parent, *node;
	size_t size;

	if (!root)
		return (NULL);
	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	size = tree_size(*root);
	parent = find_parent(*root, size + 1);
	node = binary_tree_node(parent, value);
	if (!node)
		return (NULL);
	if ((size + 1) & 1)
		parent->right = node;
	else
		parent->left = node;
	return (sift_up(node));
}
