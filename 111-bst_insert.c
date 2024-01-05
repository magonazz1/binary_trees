#include "binary_trees.h"

/**
 * bst_insert - function inserts a value in a Binary Search Tree
 *
 * @tree: Double pointer to root node of BST
 *
 * @value: Value at node
 *
 * Return: A pointer to the created node, or NULL on failure
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	binary_tree_t *node, *parent;

	if (*tree == NULL)
	{
		node = binary_tree_node(*tree, value);
		*tree = node;
		return (*tree);
	}
	node = *tree;

	while (node != NULL)
	{
		parent = node;

		if (node->n == value)
		{
			return (NULL);
		}
		if (value > node->n)
		{
			node = node->right;
		}
		else
			node = node->left;
	}

	if (value > parent->n)
	{
		parent->right = binary_tree_node(parent, value);
		return (parent->right);
	}
	else
	{
		parent->left = binary_tree_node(parent, value);
		return (parent->left);
	}
}
