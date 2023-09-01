#include "binary_trees.h"

/**
 * binary_tree_rotate_left - The performs a left rotation on a BT
 * @tree: A pointer to the root node.
 * Return: pointer to new nod.
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *new_root_left_child, *_parent;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	_parent = tree;
	new_root = tree->right;
	new_root_left_child = new_root->left;

	_parent->right = new_root_left_child;
	if (new_root_left_child != NULL)
		new_root_left_child->_parent = _parent;

	new_root->left = _parent;
	new_root->_parent = _parent->_parent;
	_parent->_parent = new_root;

	return (new_root);
}
