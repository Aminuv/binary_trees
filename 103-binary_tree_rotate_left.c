#include "binary_trees.h"

/**
 * bst_search - searches for a value in a BST.
 * @tree: pointer of the BST.
 * @value: value to search for in the tre.
 * 
 * Return: pointer to the node.
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
