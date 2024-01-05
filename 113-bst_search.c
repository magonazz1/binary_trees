#include "binary_trees.h"

/**
 * bst_search - function that Searches for a value in a Binary Search Tree
 *
 * @tree: Pointer to root node of BST
 *
 * @value: Value to be found
 *
 * Return: A pointer to the created node, or NULL on failure
 */

bst_t *bst_search(const bst_t *tree, int value)
{

	if (tree == NULL)
	{
		return (NULL);
	}

	if (value == tree->n)
	{
		return ((bst_t *)tree);
	}

	if (value < tree->n)
	{
		return (bst_search(tree->left, value));
	}

	if (value > tree->n)
	{
		return (bst_search(tree->right, value));
	}
	return (NULL);
}
