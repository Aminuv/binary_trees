#include "binary_trees.h"

size_t height(const binary_tree_t *tree);
int balance(const binary_tree_t *tree);
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent, avl_t **new, int value);
avl_t *avl_insert(avl_t **tree, int value);

/**
 * height - The Measures of the height of the binary tree.
 * @tree: A pointer to that root node.
 *
 * Return: If NULL, Or 0, else Is height.
 */
size_t height(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * balance - The Measures of the balance tree.
 * @tree: Pointer to the balance factor.
 *
 * Return: NULL, Or 0, else Is balance factor.
 */
int balance(const binary_tree_t *tree)
{
	return (tree != NULL ? height(tree->left) - height(tree->right) : 0);
}

/**
 * avl_insert_recursive - The inserts of the value 'AVL' tree.
 * @tree:   A double pointer to the root node.
 * @parent: The current working node.
 * @new:    A store of a new node.
 * @value: To insert into the 'AVL' tree.
 *
 * Return: A pointer after insertion, or NULL.
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent, avl_t **new, int value)
{
	int _factor;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	else
		return (*tree);

	_factor = balance(*tree);
	if (_factor > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (_factor < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (_factor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (_factor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}
	return (*tree);
}

/**
 * avl_insert - that inserts of value 'AVL' tree.
 * @tree: A double pointer of AVL tree.
 * @value: The value to insert of it.
 *
 * Return: A pointer, or NULL.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *_new = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &_new, value);
	return (_new);
}
