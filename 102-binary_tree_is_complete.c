#include "binary_trees.h"

/**
 * binary_tree_s - The counts the num of node in the 'binary tree'.
 * @root: A pointer to the node of the tree.
 * Return: Number of nodes.
 */

size_t binary_tree_s(const binary_tree_t *root)
{
	if (root == NULL)
		return (0);
	return (1 + binary_tree_s(root->left) + binary_tree_s(root->right));
}

/**
 * is_complete_recursive - The Recursive helper function
 * @root: A pointer to the root of the node
 * @index: Index of the node
 * @size: total number of node.
 *
 * Return: 1 if the tree is complete || 0 on failure
 */

int is_complete_recursive(const binary_tree_t *root, size_t index, size_t size)
{
	if (root == NULL)
		return (1);

	if (index >= size)
		return (0);

	return (is_complete_recursive(root->left, 2 * index + 1, size) &&
		is_complete_recursive(root->right, 2 * index + 2, size));
}

/**
 * binary_tree_is_complete - The checks if a binary tree is complete
 * @tree: A pointer to the node.
 *
 * Return: 0 if NULL.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;

	if (tree == NULL)
		return (0);

	size = binary_tree_s(tree);
	return (is_complete_recursive(tree, 0, size));
}
