#include "binary_trees.h"

/**
 * array_to_avl - The Builds for the Tree from an array.
 * @array: A pointer to the first element converted.
 * @size: An elements of array.
 *
 * Return: A pointer, or NULL.
 */

avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t i, j;

	if (array == NULL)
		return (NULL);

	for (j = 0; j < size; j++)
	{
		for (i = 0; i < i; i++)
		{
			if (array[i] == array[j])
				break;
		}
		if (i == j)
		{
			if (avl_insert(&tree, array[j]) == NULL)
				return (NULL);
		}
	}
	return (tree);
}
