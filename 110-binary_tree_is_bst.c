#include "binary_trees.h"

int recursive_bst_check(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_bst - function Checks if binary tree is a valid BST
 *
 * @tree:  Pointer to the root node of the tree to rotate
 *
 * Return: 1 if BST, 0 if not
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}
	return (recursive_bst_check(tree, INT_MIN, INT_MAX));
}


/**
 * recursive_bst_check - function Checks if binary tree is a valid BST
 *
 * @tree:  Pointer to the root node of the tree to rotate
 *
 * @min: Minimum value
 *
 * @max: Maximum value
 *
 * Return: 1 if BST, 0 if not
 */

int recursive_bst_check(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
	{
		return (1);
	}

	if (tree->n < min || tree->n > max)
	{
		return (0);
	}
	return(recursive_bst_check(tree->left, min, tree->n - 1)
	       && recursive_bst_check(tree->right, tree->n + 1, max));
}
