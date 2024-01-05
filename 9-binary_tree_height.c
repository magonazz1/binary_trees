#include "binary_trees.h"

/**
 * binary_height_recursion - function that Measures the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: The height of the tree, returns 0 if tree is NULL
 */

size_t binary_height_recursion(const binary_tree_t *tree)
{
	size_t _left = 0, _right = 0;

	if (tree == NULL)
	{
		return (0);
	}

	if (tree->left == NULL && tree->right == NULL)
	{
		return (0);
	}

	_left = binary_height_recursion(tree->left) + 1;
	_right = binary_height_recursion(tree->right) + 1;

	if (_left > _right)
	{
		return (_left);
	}
	else
	{
		return (_right);
	}
}

/**
 * binary_tree_height - function that Measures the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: The height of the tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	return (binary_height_recursion(tree));
}
