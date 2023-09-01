#include "binary_trees.h"
/**
 * binary_tree_height -The  measures for the height of a binary tree.
 * @tree: A pointer of the root node in the tree.
 * Return: if tree is NULL, or 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		int left = 0, right = 0;

		if (tree->right)
			right = 1 + binary_tree_height(tree->right);
		if (tree->left)
			left = 1 + binary_tree_height(tree->left);
		if (left > right)
			return (left);
		else
			return (right);
	}
	else
		return (0);
}
/**
 * print_at_level - print node, especific level
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node.
 * @level: level to print
 */
void print_at_level(const binary_tree_t *tree, void (*func)(int), int level)
{
	if (tree && func)
	{
		if (level == 1)
			func(tree->n);
		else
		{
			print_at_level(tree->left, func, level - 1);
			print_at_level(tree->right, func, level - 1);
		}
	}

}

/**
 * binary_tree_levelorder - For Goes through the binary tree.
 * @tree: A pointer to the root node.
 * @func: A pointer to a Function.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t ht = 0, i = 1;

	if (tree && func)
	{
		ht = binary_tree_height(tree);
		while (i <= ht + 1)
		{
			print_at_level(tree, func, i);
			i++;
		}
	}

}
