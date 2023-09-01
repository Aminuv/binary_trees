#include "binary_trees.h"

/**
 * binary_tree_s - The measures to the size of a binary tree
 * @tree: pointer to the root node.
 * Return: 0 if NULL.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t r = 0, l = 0;

	if (!tree)
		return (0);

	if (tree->r)
		r = binary_tree_size(tree->r);

	if (tree->l)
		l = binary_tree_size(tree->l);

	return (l + r + 1);
}
