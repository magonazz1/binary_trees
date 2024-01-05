#include "binary_trees.h"

/**
 * binary_tree_depth -function that  measures a node's depth in a binary tree
 *
 * @node: Pointer to the node to check
 *
 * Return: The Depth of binary tree
 */

size_t binary_tree_depth(const binary_tree_t *node)
{
	size_t count = 0;

	if (node == NULL)
	{
		return (0);
	}

	while (node->parent)
	{
		count++;
		node = node->parent;
	}
	return (count);
}

/**
 * binary_trees_ancestor - Function that finds the lowest common
 *				ancestor of two nodes
 *
 * @first: Pointer to the first node
 *
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t depth_1, depth_2;
	binary_tree_t *new1 = (binary_tree_t *)first,
		*new2 = (binary_tree_t *)second;

	if (first == NULL || second == NULL)
	{
		return (NULL);
	}

	depth_1 = binary_tree_depth(first);
	depth_2 = binary_tree_depth(second);

	while (depth_2 > depth_1)
	{
		new2 = new2->parent;
		depth_2--;
	}
	while (depth_1 > depth_2)
	{
		new1 = new1->parent;
		depth_2--;
	}
	while (new1 && new2)
	{
		if (new1 == new2)
		{
			return (new1);
		}
		new1 = new1->parent;
		new2 = new2->parent;
	}
	return (NULL);
}
