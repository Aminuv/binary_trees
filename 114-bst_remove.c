#include "binary_trees.h"

/**
 * BstFindMin - finds the minimum value
 * @node: pointer to the node
 * Return: NULL if node is NULL
 */

bst_t *BstFindMin(bst_t *node)
{
	if (node == NULL)
		return (NULL);

	while (node->left != NULL)
		node = node->left;
	return (node);
}

/**
 * bst_remove - For the removes of a node from the 'BST'.
 * @root: A pointer to the node of it.
 * @value: value to remove from it.
 *
 * Return: A pointer.
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

		tmp = BstFindMin(root->right);
		root->n = tmp->n;

		root->right = bst_remove(root->right, tmp->n);
	}
	return (root);
}
