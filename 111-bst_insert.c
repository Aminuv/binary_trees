#include "binary_trees.h"

/**
 * bst_insert - The inserts of value in a BST.
 * @tree: double pointer to the node
 * @value: value to store in the node.
 *
 * Return: pointer to the cre or, NULL.
 */

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *_new, *_tr;

	if (tree == NULL || *tree == NULL)
	{
		_new = binary_tree_node(NULL, value);
		*tree = _new;
		return (_new);
	}

	_tr = *tree;

	while (_tr != NULL)
	{
		if (_tr->n == value)
			return (NULL);
		if (_tr->n > value)
		{
			if (_tr->left == NULL)
			{
				_tr->left = binary_tree_node(_tr, value);
				return _tr->left);
			}
			_tr = _tr->left;
		}
		if (_tr->n < value)
		{
			if (_tr->right == NULL)
			{
				_tr->right = binary_tree_node(_tr, value);
				return (_tr->right);
			}
			_tr = _tr->right;
		}
	}
	return (NULL);
}
