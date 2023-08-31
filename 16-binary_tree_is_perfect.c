#include "binary_trees.h"

size_t _max(size_t a, size_t b);
/**
 * _max - To find max of two num
 * @a: A number
 * @b: A number
 *
 * Return: MAX of two num
 */
size_t _max(size_t a, size_t b)
{
	return (a > b ? a : b);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: tree
 *
 * Return: balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	binary_tree_t *tempChild = NULL, *tempTree = (binary_tree_t *) tree;
	int lh = 0, r_h = 0;

	if (!tree)
		return (0);
	tempChild = tempTree->right;
	tempTree->right = NULL;
	lh = (int) binary_tree_height(tempTree);
	tempTree->right = tempChild;
	tempChild = tempTree->left;
	tempTree->left = NULL;
	r_h = (int) binary_tree_height(tempTree);
	tempTree->left = tempChild;
	return (lh - r_h);
}

/**
 * binary_tree_height - height of a tree
 * @tree: tree
 *
 * Return: height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree && (tree->left || tree->right))
		return (1 + _max(binary_tree_height(tree->left),
					binary_tree_height(tree->right)));
	return (0);
}

/**
 * binary_tree_is_perfect - The check if a binary tree is perfect
 * @tree: The tree
 *
 * Return: 1 or, 0.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int R = 1;

	if (!tree || binary_tree_balance(tree) != 0)
		return (0);
	if (tree->left)
		R = R & binary_tree_is_perfect(tree->left);
	if (tree->right)
		R = R & binary_tree_is_perfect(tree->right);
	return (R);
}
