#include "binary_trees.h"

/**
 * binary_tree_node - function that Creates a binary tree node
 *
 * @parent: Parent node
 *
 * @value: Value of node
 *
 * Return: Create new Binary tree
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	/*Assign data to this node*/
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}
