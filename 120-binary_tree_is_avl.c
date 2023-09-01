#include "binary_trees.h"

/**
 * binary_tree_is_leaf -  The checker for the node in leaf.
 * @node: is a pointer of the node for checker.
 *
 * Return: return 1, or 0.
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->right == NULL && node->left == NULL)
		return (1);
	else
		return (0);
}

/**
 * binary_tree_leaves - The number of the leaves.
 * @tree: A pointer to the root node.
 *
 * Return: NULL, or 0.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	else
		return (binary_tree_is_leaf(tree) +
			binary_tree_leaves(tree->right) +
			binary_tree_leaves(tree->left));

}
