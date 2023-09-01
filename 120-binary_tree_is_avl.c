#include "binary_trees.h"
#include <limits.h>

/**
 * height - A height of the tree
 * @tree: the tree
 *
 * Return: the height of it.
 */

int_height(const binary_tree_t *tree)
{
	int l_height, r_height;

	if (tree == NULL)
		return (0);
	l_height =_height(tree->left);
	r_height =_height(tree->right);

	return (1 + ((l_height > r_height) ? l_height : r_height));
}

/**
 * is_bst - The checks if the binary tree is a 'BST'.
 * @tree: A pointer to the root node
 * @prev: A pointer to the int holding traversed value
 * Return: 1 or, 0 if is NULL.
 */
int is_bst(const binary_tree_t *tree, int *prev)
{
	if (tree == NULL)
		return (1);
	if (!is_bst(tree->left, prev))
		return (0);
	if (*prev >= tree->n)
		return (0);

	*prev = tree->n;

	return (is_bst(tree->right, prev));
}

/**
 * binary_tree_is_avl - checks if a BT is an AVL tree
 * @tree: pointer to the root node
 * Return: 1 if tree is valid AVL, 0 on failure
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int left_h, right_h, balance_factor;
	int prev = INT_MIN;

	if (tree == NULL)
		return (0);

	if (!is_bst(tree, &prev))
		return (0);

	left_h =_height(tree->left);
	right_h =_height(tree->right);
	balance_factor = left_h - right_h;

	return ((balance_factor >= -1 && balance_factor <= 1) &&
		binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}
