#include "binary_trees.h"

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 * @root: Double pointer to the root node of heap
 *
 * Return: Value stored in the root node, or 0 on failure
 */
int heap_extract(heap_t **root)
{
    if (root == NULL || *root == NULL)
        return 0;

    int value = (*root)->n;
    heap_t *last_node = find_last_node(*root);

    if (*root == last_node)
    {
        free(*root);
        *root = NULL;
        return value;
    }

    swap_nodes(*root, last_node);
    if (last_node->parent->left == last_node)
        last_node->parent->left = NULL;
    else
        last_node->parent->right = NULL;

    free(last_node);
    heapify_down(*root);

    return value;
}

/**
 * find_last_node - Finds the last level-order node in a heap
 * @root: Pointer to the root node of the heap
 *
 * Return: Pointer to the last level-order node
 */
heap_t *find_last_node(heap_t *root)
{
    if (root == NULL)
        return NULL;

    heap_t *last_node = NULL;
    int height = get_tree_height(root);
    int mask = 1 << (height - 1);

    while (root != NULL)
    {
        last_node = root;
        if (mask & root->index)
            root = root->right;
        else
            root = root->left;

        mask >>= 1;
    }

    return last_node;
}

/**
 * get_tree_height - Calculates the height of a binary tree
 * @root: Pointer to the root node of the tree
 *
 * Return: Height of the tree
 */
int get_tree_height(heap_t *root)
{
    if (root == NULL)
        return 0;

    int left_height = get_tree_height(root->left);
    int right_height = get_tree_height(root->right);

    return 1 + (left_height > right_height ? left_height : right_height);
}

/**
 * swap_nodes - Swaps two nodes in a binary tree
 * @node1: Pointer to the first node
 * @node2: Pointer to the second node
 */
void swap_nodes(heap_t *node1, heap_t *node2)
{
    int temp = node1->n;
    node1->n = node2->n;
    node2->n = temp;
}

/**
 * heapify_down - Restores the heap property by moving down the tree
 * @root: Pointer to the root node of the heap
 */
void heapify_down(heap_t *root)
{
    heap_t *largest = root;
    heap_t *left = root->left;
    heap_t *right = root->right;

    if (left != NULL && left->n > largest->n)
        largest = left;

    if (right != NULL && right->n > largest->n)
        largest = right;

    if (largest != root)
    {
        swap_nodes(root, largest);
        heapify_down(largest);
    }
}

