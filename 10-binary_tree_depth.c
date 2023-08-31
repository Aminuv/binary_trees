#include "binary_trees.h"

/**
 * binary_tree_depth - The measures depth (dpt) of node.
 * @tree: pointer to the node of measure.
 * Return: 0 if NULL.
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t dpt = 0;

	if (tree == NULL)
		return (0);

	if (tree->parent)
		dpt += 1 + binary_tree_depth(tree->parent);
	return (dpt);
}
