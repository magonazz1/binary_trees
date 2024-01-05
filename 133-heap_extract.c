#include "binary_trees.h"

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;

	if (root == NULL || *root == NULL)
	{
		return (0);
	}

	value = (*root)->n;
	heap_t *last_node = find_last_node(*root);

	if (*root == last_node)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	swap_nodes(*root, last_node);
	if (last_node->parent->left == last_node)
	{
		last_node->parent->left = NULL;
	}
	else
	{
		last_node->parent->right = NULL;
	}

	free(last_node);
	heapify_down(*root);

	return (value);
}
