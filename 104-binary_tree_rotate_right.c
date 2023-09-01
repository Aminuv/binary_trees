#include "binary_trees.h"

/**
 * binary_tree_rotate_right - The performs a right rotation on a BT
 * @tree: A pointer to the node.
 * Return: A pointer.
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root, *new_root_right_child, *_parent;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	/*storing the ref of the nodes invloved */
	_parent = tree;
	new_root = tree->left;
	new_root_right_child = new_root->right;

	/* rotating right */
	_parent->left = new_root_right_child;
	if (new_root_right_child != NULL)
		new_root_right_child->_parent = _parent;

	new_root->right = _parent;
	new_root->_parent = _parent->_parent;
	_parent->_parent = new_root;

	return (new_root);
}
