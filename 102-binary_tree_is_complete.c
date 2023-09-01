#include "binary_trees.h"

/**
 * array_to_bst - builds a BST from an array
 * @array: pointer to the first element to be converted
 * @size: number of elements in the array
 * 
 * Return: pointer to the node or, NULL.
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
