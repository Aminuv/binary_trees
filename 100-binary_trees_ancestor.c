#include "binary_trees.h"

/**
 * binary_trees_ancestor - The finds the lowest common ancestor.
 * @first: pointer to the first node.
 * @second: pointer to the second node.
 *
 * Return: pointer to the LCA or, NULL.
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	const binary_tree_t *l_LCA, *r_LCA;

	for (l_LCA = first; l_LCA; l_LCA = l_LCA->parent)
		for (r_LCA = second; r_LCA; r_LCA = r_LCA->parent)
			if (l_LCA == r_LCA)
				return ((binary_tree_t *)l_LCA);
	return (NULL);
}
