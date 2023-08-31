#include "binary_trees.h"

/**
 * binary_tree_insert_right - for insert right child
 * @parent: pointer to the node.
 * @value: value to the stor.
 * Return: pointer to right child.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *r_child;

	if (parent == NULL)
		return (NULL);

	r_child = malloc(sizeof(binary_tree_t));

	if (r_child == NULL)
		return (NULL);

	r_child->parent = parent;
	r_child->n = value;
	r_child->left = NULL;
	r_child->right = parent->right;

	parent->right = r_child;

	if (r_child->right)
	{
		r_child->right->parent = r_child;
	}

	return (r_child);
}
