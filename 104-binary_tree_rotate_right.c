#include "binary_trees.h"

/**
 * binary_tree_rotate_right - function that performs a right-rotation on a binary tree
 *
 * @tree:  Pointer to the root node of the tree to rotate
 *
 * Return: If tree is NULL, return 0, else  uncle
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *old_root = NULL;

	if (tree == NULL)
	{
		return (tree);
	}

	new_root = tree->left;
	tree->left = new_root->right;

	if (new_root->right != NULL)
	{
		new_root->right->parent = tree;
	}

	new_root->parent = tree->parent;

	if (tree->parent == NULL)
	{
		old_root = new_root;
	}
	else if (tree == tree->parent->right)
	{
		tree->parent->right = new_root;
	}
	else
	{
		tree->parent->left = new_root;
	}
	new_root->right = tree;

	tree->parent = new_root;

	if (old_root)
	{
		return (old_root);
	}
	return (new_root);
}
