#include "binary_trees.h"

/**
 * binary_tree_sibling - Function that finds the sibling of a node
 *
 * @node: Pointer to the node to find the uncle
 *
 * Return: If tree is NULL, return 0, else  uncle
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
	{
		return (NULL);
	}

	if (node->parent->left == node)
	{
		return (node->parent->right);
	}

	if (node->parent->right == node)
	{
		return (node->parent->left);
	}
	return (NULL);
}
