#include "binary_trees.h"

/**
 * binary_tree_rotate_left - function that performs a left-rotation
 *				on a binary tree
 *
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: If tree is NULL, return 0, else  uncle
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *old_root = NULL;

	if (tree == NULL)
	{
		return (tree);

	}

	new_root = tree->right;
	tree->right = new_root->left;

	if (new_root->left != NULL)
	{
		new_root->left->parent = tree;
	}

	new_root->parent = tree->right;

	if (tree->parent == NULL)
	{
		old_root = new_root;
	}
	else if (tree == tree->parent->left)
	{
		tree->parent->left = new_root;
	}
	else
	{
		tree->parent->right = new_root;
	}
	new_root->left = tree;

	tree->parent = new_root;

	if (old_root)
	{
		return (old_root);
	}
	return (new_root);
}
