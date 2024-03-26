#include "binary_trees.h"

/**
 * array_to_bst - Builds a Binary Search tree from an array.
 *
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of element in the array
 *
 * Return: A pointer to the root node of the created BST, or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tr = NULL;
	size_t ind, jayind;

	if (array == NULL)
		return (NULL);

	for (ind = 0; ind < size; ind++)
	{
		for (jayind = 0; jayind < ind; jayind++)
		{
			if (array[jayind] == array[ind])
				break;
		}
		if (jayind == ind)
		{
			if (bst_insert(&tr, array[ind]) == NULL)
				return (NULL);
		}
	}

	return (tr);
}
