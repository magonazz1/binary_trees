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
 * binary_tree_is_perfect - Measures the balance factor of a binary tree
 *
 * @tree: Pointer to the root node of the tree to traverse
 *
 * Return: If tree is NULL, return 0, else balance
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int tree_height, tree_size, count = 0;
	int balanced = 1;

	if (tree == NULL)
	{
		return (0);
	}

	tree_height = binary_tree_height(tree);
	tree_size = binary_tree_size(tree);

	for (; count <= tree_height; count++)
		balanced *= 2;

	if (balanced - 1 == tree_size)
	{
		return (1);
	}

	return (0);

}

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
 * Return: The height of the tree, returns 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	return (binary_height_recursion(tree));
}
