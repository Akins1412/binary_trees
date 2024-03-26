#include "binary_trees.h"

/**
 * binary_tree_leaves - numbers the leaves in a binary tree.
 * @tree: Points to a root node of the tree to find the number of leaves.
 * Return: 0 if tree is NULL.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t lvvs = 0;

	if (tree)
	{
		lvvs += (!tree->left && !tree->right) ? 1 : 0;
		lvvs += binary_tree_leaves(tree->left);
		lvvs += binary_tree_leaves(tree->right);
	}

	return (lvvs);
