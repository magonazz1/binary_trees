#include "binary_trees.h"

void print_level_order(const binary_tree_t *tree,
		       int level, void (*func)(int));
int tree_height(const binary_tree_t *tree);
int get_height(const binary_tree_t *tree);

/**
 * binary_tree_levelorder - function to traveres binary tree using
 *				level-order traversal
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * @func: Pointer to a function to call for each node
 *
 * Return: If tree is NULL, return 0, else  uncle
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int height;
	int index;

	if (tree == NULL)
	{
		return;
	}

	if (func == NULL)
	{
		return;
	}

	height = tree_height(tree);

	for (index = 1; index <= height; index++)
	{
		print_level_order(tree, index, func);
	}
}

/**
 * print_level_order - function to traveresthe each level of Tree
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * @level: Counts which level currently at
 *
 * @func: Pointer to a function to call for each node
 *
 * Return: Void type return
 */

void print_level_order(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree == NULL)
	{
		return;
	}

	if (level == 1)
	{
		func(tree->n);
	}
	else if (level > 1)
	{
		print_level_order(tree->left, level - 1, func);
		print_level_order(tree->right, level - 1, func);
	}
}

/**
 * get_height - function to measures the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: The height of the tree, returns 0 if tree is NULL
 */

int get_height(const binary_tree_t *tree)
{
	int _left, _right;

	if (tree == NULL)
	{
		return (0);
	}

	_left = tree_height(tree->left);
	_right = tree_height(tree->right);

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
 * tree_height - function that measures the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree
 *
 * Return: The height of the tree
 */

int tree_height(const binary_tree_t *tree)
{
	return (get_height(tree));
}
