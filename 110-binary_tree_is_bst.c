#include "binary_trees.h"
#include <limits.h>

/**
 * isvalidBST - The perform inorder Travesal.
 * @node: A pointer to the node
 * @prev: A pointer to the int holding traver.
 * Return: 1 or, 0
 */

int isvalidBST(const binary_tree_t *node, int *prev)
{
	if (node == NULL)
		return (1);

	if (!isvalidBST(node->left, prev))
		return (0);

	if (*prev >= node->n)
		return (0);

	*prev = node->n;

	return (isvalidBST(node->right, prev));
}

/**
 * binary_tree_is_bst - The checks if a binary tree is a 'BST'
 * @tree: A pointer to the node.
 *
 * Return: 1 if valid, 0 if not or' 0 if NULL.
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	int prv = INT_MIN;

	if (tree == NULL)
		return (0);


	return (isvalidBST(tree, &prv));
}
