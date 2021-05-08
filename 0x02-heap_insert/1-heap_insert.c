#include "binary_trees.h"

/**
 * heap_insert - Creates a binary tree node.
 *
 * @root: Double pointer to the root node of the Heap.
 * @value: Value to store in the node to be inserted.
 * Return: A pointer to the inserted node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    heap_t *new_node = NULL;
        
    new_node =  malloc(sizeof(heap_t));
    if (!new_node)
    {
        return (NULL);
    }
        
    new_node->n = value;
        
    if (*root == NULL)
    {
        *root = binary_tree_node(*root, value);
    }
    else
    {
            
    }
    return (new_node);
}