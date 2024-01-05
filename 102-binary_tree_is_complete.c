#include "binary_trees.h"

/**
 * binary_tree_size - function that measures the size of a binary tree
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: If tree is NULL, the function will return 0
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	return (1 + binary_tree_size(tree->left) +
		binary_tree_size(tree->right));
}

/**
 * check_if_complete - function that checks if tree is complete
 *
 * @tree: Pointer to the root node of the tree
 *
 * @index: index of where the node is located
 *
 * @size: size of the tree
 *
 * Return: 1 if complete, otherwise 0 if not
 */

int check_if_complete(const binary_tree_t *tree, size_t index, size_t size)
{
	if (tree == NULL)
	{
		return (1);
	}
	if (index >= size)
	{
		return (0);
	}
	return (check_if_complete(tree->left, index * 2 + 1, size) &&
		check_if_complete(tree->right, index * 2 + 2, size));
}

/**
 * binary_tree_is_complete - function that checks if a binary tree is complete
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if complete, otherwise 0 if not
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
	{
		return (0);
	}

	size = binary_tree_size(tree);
	return (check_if_complete(tree, 0, size));
}
