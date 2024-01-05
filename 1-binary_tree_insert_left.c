#include "binary_trees.h"

/**
 * binary_tree_insert_left - function that creates a new binary branch
 *				on the left
 *
 * @parent: Parent node
 *
 * @value: Value of node
 *
 * Return: Create a new Binary tree
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node;


	if (parent == NULL)
	{
		return (NULL);
	}

	node  = malloc(sizeof(binary_tree_t));

	if (node == NULL)
	{
		return (NULL);
	}
	node->n = value;
	node->parent = parent;
	node->right = NULL;

	if (parent->left == NULL)
	{
		parent->left = node;
		node->left = NULL;
	}
	else
	{
		node->left = parent->left;
		parent->left->parent = node;
		parent->left = node;
	}
	return (node);
}
