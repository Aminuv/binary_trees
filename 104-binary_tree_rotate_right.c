#include "binary_trees.h"

/**
 * binary_tree_rotate_right - The performs a right rotation on a BT
 * @tree: A pointer to the node.
 * Return: A pointer.
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *new_root_right_child, *parent;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	parent = tree;
	new_root = tree->left;
	new_root_right_child = new_root->right;

	parent->left = new_root_right_child;
	if (new_root_right_child != NULL)
		new_root_right_child->parent = parent;

	new_root->right = parent;
	new_root->parent = parent->parent;
	parent->parent = new_root;

	return (new_root);
}
