#include "binary_trees.h"

/**
 * binary_tree_uncle - The Finds the uncle of a  node.
 * @node: pointer to the node.
 * 
 * Return: pointer or, NULL on failure
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (node == NULL)
		return (NULL);

	return (sib_ling(node->parent));
}

/**
 * sib_ling - gets the sib_ling node to find uncle
 * @node: pointer to the node to find sib_ling from
 * Return: sib_ling of node
 */

binary_tree_t *sib_ling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	else
		return (node->parent->left);
}
