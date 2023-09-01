#include "binary_trees.h"

/**
 * bst_search - The searches for the value in 'BST'.
 * @tree: A pointer of the 'BST'.
 * @value: A value to the search for the tre.
 *
 * Return: A pointer.
 */


bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL || tree->n == value)
		return ((bst_t *)tree);

	if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));
}
