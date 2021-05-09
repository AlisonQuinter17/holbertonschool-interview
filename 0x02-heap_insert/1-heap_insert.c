#include "binary_trees.h"

/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 *
 * @root: Double pointer to the root node of the Heap.
 * @value: Value to store in the node to be inserted.
 * Return: A pointer to the inserted node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	new_node = binary_tree_node(*root, value);
	if (!new_node)
	{
		return (NULL);
	}
	if (!(*root))
	{
		return (*root = new_node);
	}
	new_node = max_heap_ordering(*root, value, 1,
				     binary_tree_size(*root) + 1);
	return (max_heap(new_node));
}

/**
 * insert_by_level - Insert node by sort level.
 *
 * @tree: Pointer to the parent node of the tree.
 * @value: Value to store in the node to be inserted.
 * @index: Node index.
 * @total_nodes: Total number of nodes in the tree.
 * Return: A pointer to the node inserted.
 */
heap_t *insert_by_level(heap_t *tree, int value, size_t index, size_t total_nodes)
{
	heap_t *left_branch, *right_branch;

	if (!tree)
		return (NULL);

	if ((total_nodes / 2) == index)
	{
		return ((total_nodes % 2) == 0 ? (tree->left = binary_tree_node(tree, value)) : (tree->right = binary_tree_node(tree, value)));
	}
	else
	{
		left_branch = max_heap_ordering(tree->left, value, index * 2, total_nodes);
		right_branch = max_heap_ordering(tree->right, value, index * 2 + 1, total_nodes);
		return (left_branch ? left_branch : right_branch);
	}
}

/**
 * binary_tree_size - measures the size of a binary tree
 *
 * @root: a pointer to the root node of the tree to measure the size
 * Return: size of binary tree or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *root)
{
	size_t left_size = 0, right_size = 0;

	if (!root)
		return (0);

	return ((left_size = binary_tree_size(root->left)) + (right_size = binary_tree_size(root->right)) + 1);
}

/**
 * max_heap - Sort the nodes of the tree from maximum to smallest value.
 *
 * @node: Pointer to the node to evaluate and sort.
 * Return: Pointer to starting node.
 */
heap_t *max_heap(heap_t *node)
{
	while (node && node->parent && node->n > node->parent->n)
	{
		node->parent->n -= node->n;
		node->n = node->parent->n + node->n;
		node->parent->n = node->n - node->parent->n;
		node = node->parent;
	}
	return (node);
}
