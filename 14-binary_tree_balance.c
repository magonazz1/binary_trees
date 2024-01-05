#include "binary_trees.h"

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 *
 * @tree: Pointer to the root node of the tree to traverse
 *
 * Return: If tree is NULL, return 0, else balance
 */

int binary_tree_balance(const binary_tree_t *tree)
{

	if (tree == NULL)
	{
		return (0);
	}

	if (tree->left == NULL && tree->right == NULL)
	{
		return (0);
	}
	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
 * binary_height_recursion - it Measures the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: The height of the tree, returns 0 if tree is NULL
 */

size_t binary_height_recursion(const binary_tree_t *tree)
{
	size_t _left, _right;

	if (tree == NULL)
	{
		return (0);
	}

	_left = binary_height_recursion(tree->left);
	_right = binary_height_recursion(tree->right);

	if (_left > _right)
	{
		return (_left + 1);
	}
	else
	{
		return (_right + 1);
	}
}

/**
 * binary_tree_height - it Measures the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: The height of the tree, returns 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	return (binary_height_recursion(tree) - 1);
}
