#include "binary_trees.h"

/**
 * binary_tree_height - Measuring the height of a binary tree.
 * @tree: Points to the root node of the tree to find height.
 * Return: Height of the tree [SUCCESS] or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lt_ht = 0;
	size_t rh_ht = 0;

	if ((tree == NULL) ||
	(tree->left == NULL && tree->right == NULL))
		return (0);

	lt_ht = binary_tree_height(tree->left);
	rh_ht = binary_tree_height(tree->right);

	if (lt_ht > rh_ht)
		return (lt_ht + 1);
	return (rh_ht + 1);
}
