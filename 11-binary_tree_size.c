#include "binary_trees.h"

/**
 * binary_tree_s - The measures to the size of a binary tree
 * @tree: pointer to the root node.
 * Return: 0 if NULL.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t im = 1;

	if (!tree)
		return (0);

	im += binary_tree_size(tree->left);
	im += binary_tree_size(tree->right);

	return (im);
}
