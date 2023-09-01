#include "binary_trees.h"

/**
 * bst_findMin - the finds the minimum Value
 * @node: A pointer to the node
 * Return: NULL if NULL
 */

bst_t *bst_findMin(bst_t *node)
{
	if (node == NULL)
		return (NULL);

	while (node->left != NULL)
		node = node->left;
	return (node);
}

/**
 * bst_remove - For removing the node from a 'BST'.
 * @root: A pointer to the 'BST'.
 * @value: A value to remove from the 'BST'.
 * Return: Pointer.
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			tmp = root->right;
			free(root);
			return (tmp);
		}
		else if (root->right == NULL)
		{
			tmp = root->left;
			free(root);
			return (tmp);
		}

		tmp = bst_findMin(root->right);
		root->n = tmp->n;

		root->right = bst_remove(root->right, tmp->n);
	}
	return (root);
}
