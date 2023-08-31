#include "binary_trees.h"

/**
 * binary_tree_node - creates the binary tree for this node
 * @parent: pointer to the parent the node
 * @value: Value of new node
 * Return: ponter to the new node || NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *n_nodee;

	/* allocate memory to the root node */
	n_nodee = malloc(sizeof(binary_tree_t));

	/* check if mem allocation was a success */
	if (n_nodee == NULL)
		return (NULL);

	/* node with value but no children */
	n_nodee->parent = parent;
	n_nodee->n = value;
	n_nodee->left = NULL;
	n_nodee->right = NULL;

	return (n_nodee);
}
