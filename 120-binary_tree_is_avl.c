#include "binary_trees.h"

/**
 * binary_tree_is_avl - function that Checks if binary tree is a valid AVL
 *
 * @tree:  Pointer to the root node of the tree to rotate
 *
 * Return: 1 if AVL, 0 if not
 */

int recursive_avl_check(const binary_tree_t *tree, int min, int max);

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (recursive_avl_check(tree, INT_MIN, INT_MAX));
}

/**
 * recursive_avl_check - function Checks if binary tree is a valid BST
 *
 * @tree:  Pointer to the root node of the tree to rotate
 *
 * @min: Minimum value
 *
 * @max: Maximum value
 *
 * Return: 1 if BST, 0 if not
 */

int recursive_avl_check(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
	{
		return (1);
	}

	if (tree->n < min || tree->n > max)
	{
		return (0);
	}
	return(recursive_avl_check(tree->left, min, tree->n - 1)
	       && recursive_avl_check(tree->right, tree->n + 1, max));
}
