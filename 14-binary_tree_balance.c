#include "binary_trees.h"

/**
 * binary_tree_balance - The Measures the balance a factor of binary tree
 * @tree: pointer to the root node.
 *
 * Return: 0 if is NULL.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	size_t l_height, r_height;

	if (tree == NULL)
		return (0);

	l_height = binary_tree_height(tree->left);
	r_height = binary_tree_height(tree->right);

	return (l_height - r_height);
}

/**
 * binary_tree_height - The Calculate height of a binary tree.
 * @tree: pointer to the root node
 *
 * Return: 0 or,height of tree.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l_height = 0;
	size_t r_height = 0;

	if (tree == NULL)
		return (0);

	l_height += 1 + binary_tree_height(tree->left);
	r_height += 1 + binary_tree_height(tree->right);

	if (l_height > r_height)
		return (l_height);
	else
		return (r_height);
}
