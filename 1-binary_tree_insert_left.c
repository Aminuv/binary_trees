#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a left child.
 * @parent: pointer to the node.
 * @value: value to store in the left child
 * Return: pointer to the left child 
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *l_child;

	if (parent == NULL)
		return (NULL);

	l_child = malloc(sizeof(binary_tree_t));

	if (l_child == NULL)
		return (NULL);

	l_child->parent = parent;
	l_child->n = value;
	l_child->left = parent->left;
	l_child->right = NULL;
	parent->left = l_child;

	if (l_child->left)
	{
		l_child->left->parent = l_child;
	}

	return (l_child);
}
