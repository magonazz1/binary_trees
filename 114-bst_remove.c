#include "binary_trees.h"

/**
 * min_value - function to return min-max values
 *
 * @node:  Pointer to the root node of the tree to rotate
 *
 * Return: 1 if BST, 0 if not
 */

bst_t *min_value(bst_t *node)
{
	bst_t *current = node;

	if (node == NULL)
	{
		return (NULL);
	}

	while (current->left != NULL)
	{
		current = current->left;
	}
	return (current);
}

/**
 * bst_remove - function that removes a node in a Binary Search Tree
 *
 * @root: Pointer to root node of BST
 *
 * @value: Value to be found
 *
 * Return: A pointer to new root node, or NULL on failure
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp = NULL;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else if (value == root->n)
	{
		if (root->left == NULL && root->right == NULL)
		{free(root);
			return (NULL);
		}
		if (root->left == NULL)
		{ temp = root->right;
			if (root->parent)
			{
				if (root->parent->left == root)
					root->parent->left = temp;
				else
					root->parent->right = temp;
			} temp->parent = root->parent, free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{temp = root->left;
			if (root->parent)
			{
				if (root->parent->left == root)
					root->parent->left = temp;
				else
					root->parent->right = temp;
			} temp->parent = root->parent, free(root);
			return (temp);
		}
		else
		{temp = min_value(root->right), root->n = temp->n;
			root->right = bst_remove(root->right, temp->n);
		} } return (root); }
