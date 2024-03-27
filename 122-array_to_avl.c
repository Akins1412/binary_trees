#include "binary_trees.h"

/**
 * array_to_avl - builds an AVL tree from an array.
 *
 * @array: a ptr to the 1st element of the array to be converted.
 * @size: the number of elements in the array.
 * Return: a ptr to the root node of the created AVL tree, NULL [failure].
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t id_1, id_2;

	if (array == NULL)
		return (NULL);

	for (id_1 = 0; id_1 < size; id_1++)
	{
		for (id_2 = 0; id_2 < id_1; id_2++)
		{
			if (array[id_2] == array[id_1])
				break;
		}
		if (id_2 == id_1)
		{
			if (avl_insert(&tree, array[id_1]) == NULL)
				return (NULL);
		}
	}

	return (tree);
}
