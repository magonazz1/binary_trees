#include "binary_trees.h"

/**
 * binary_tree_leaves - function that Counts the leaves in a binary tree
 *
 * @tree: Pointer to the root node of the tree to traverse
 *
 *
 * Return: If tree is NULL return 0, else leaves
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	if (tree->left == NULL || tree->right == NULL)
	{
		return (1);
	}
	else
	{
		return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
	}
}
