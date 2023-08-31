#include "binary_trees.h"

/**
 * binary_tree_size - The measures to the size of a binary tree
 * @tree: pointer to the root node.
 * Return: 0 if NULL.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t l_size, rightsize;

	if (tree == NULL)
		return (0);

	l_size = binary_tree_size(tree->left);
	r_size = binary_tree_size(tree->right);

	return (l_size + r_size + 1);
}
