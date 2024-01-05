#include "binary_trees.h"

/**
 * binary_tree_depth - function that measures the depth of
 *			a node in a binary tree
 *
 * @tree: Pointer to the root node of the tree to traverse
 *
 *
 * Return: If tree or func is NULL, do nothing
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;
	const binary_tree_t *node;

	if (tree == NULL)
	{
		return (0);
	}

	if (tree)
	{
		node = tree;
		for (depth = 0; node->parent != NULL; node = node->parent)
		{
			depth++;
		}
	}
	return (depth);
}
