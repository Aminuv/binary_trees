#include "binary_trees.h"

/**
 * array_to_bst - The builds a 'BST' from an array.
 * @array: A pointer to the first element.
 * @size: A number of an element.
 *
 * Return: pointer or, NULL.
 */

bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *tr = NULL;

	for (i = 0; i < size; i++)
	{
		bst_insert(&tr, array[i]);
	}

	return (tr);
}
