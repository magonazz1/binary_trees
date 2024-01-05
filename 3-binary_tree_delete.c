#include "binary_trees.h"

/**
 * binary_tree_delete - function that Deletes the whole binary tree
 * @tree: The root address of the binary tree
 */

void binary_tree_delete(binary_tree_t *tree)
{
	if (tree)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
