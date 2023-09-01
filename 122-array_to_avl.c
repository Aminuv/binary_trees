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
	size_t a, b;

	if (array == NULL)
		return (NULL);

	for (a = 0; a < size; a++)
	{
		for (b = 0; b < a; b++)
		{
			if (array[b] == array[a])
				break;
		}
		if (b == a)
		{
			if (avl_insert(&tree, array[a]) == NULL)
				return (NULL);
		}
	}
	return (tree);
}
