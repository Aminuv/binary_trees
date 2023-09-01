#include "binary_trees.h"

/**
 * binary_tree_rotate_left - The performs a left rotation on a BT
 * @tree: A pointer to the root node.
 * Return: pointer to new nod.
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *new_root_left_child, *parent;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	parent = tree;
	new_root = tree->right;
	new_root_left_child = new_root->left;

	parent->right = new_root_left_child;
	if (new_root_left_child != NULL)
		new_root_left_child->parent = parent;

	new_root->left = parent;
	new_root->parent = parent->parent;
	parent->parent = new_root;

	return (new_root);
}
