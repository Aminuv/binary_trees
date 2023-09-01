#include "binary_trees.h"

/**
 * * binary_tree_height_aux -  the root of that tree.
 * * @tree: A Pointer to
 *
 * Return: the Trees
 */

size_t binary_tree_height_aux(const binary_tree_t *tree)
{
	size_t h_left = 0, h_right = 0;

	if (!tree)
		return (0);
	if (tree->left)
		h_left = 1 + binary_tree_height_aux(tree->left);
	if (tree->right)
		h_right = 1 + binary_tree_height_aux(tree->right);

	if (h_left > h_right)
		return (h_left);
	return (h_right);
}

/**
 * print_level_order - print each
 * @tree: A Pointer to thse
 * @level: THe level of  tree
 * @func: A pointer to the  node
 *
 * Return: Void
 */

void print_level_order(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (!tree)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		print_level_order(tree->left, level - 1, func);
		print_level_order(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - The function that goes through a nods
 * binary A tree.
 * @tree: A pointer to  root node.
 * @func: A pointer to a function.
 *
 *Return: Void
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int _height = 0;
	int _len = 1;

	if (!tree || !func)
		return;

	_height = binary_tree_height_aux(tree) + 1;

	while (_len <= height)
	{
		print_level_order(tree, _len, func);
		len++;
	}
}
