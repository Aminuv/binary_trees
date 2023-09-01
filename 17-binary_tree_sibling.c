#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sib_ling of a node
 * @node: pointer to the node to find the sib_ling
 * Return: NULL if node or _parent are NULL or no sib_ling found
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	else
		return (node->parent->left);
}
