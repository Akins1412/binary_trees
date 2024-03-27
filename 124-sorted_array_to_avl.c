#include "binary_trees.h"

avl_t *_sort(avl_t *parent, int *array, int begin, int last);

/**
 * sorted_array_to_avl - builds an AVL tree from an array.
 *
 * @array: a ptr to the 1st element of the array.
 * @size: the num of elements in the array.
 *
 * Return: ptr to the root node of the created AVL tree, NULL [failure].
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (_sort(NULL, array, 0, ((int)(size)) - 1));
}

/**
 * _sort - creates a tree using half of the elements of the array.
 *
 * @parent: ptr to the parent of the node
 * @array: ptr to the sorted array.
 * @begin: where the array starts.
 * @last: where the array ends.
 * Return: the created tree.
 */
avl_t *_sort(avl_t *parent, int *array, int begin, int last)
{
	avl_t *src;
	binary_tree_t *au;
	int middle = 0;

	if (begin <= last)
	{
		middle = (begin + last) / 2;
		au = binary_tree_node((binary_tree_t *)parent, array[middle]);
		if (au == NULL)
			return (NULL);
		src = (avl_t *)au;
		src->left = _sort(src, array, begin, middle - 1);
		src->right = _sort(src, array, middle + 1, last);
		return (src);
	}
	return (NULL);
}
