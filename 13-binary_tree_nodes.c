#include "binary_trees.h"

/**
 * binary_tree_nodes - numbers the nodes with at least 1 child in a binary.
 * @tree: Points to the root node of a tree to count the num of nodes.
 * Return: 0 if tree is NULL.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (tree == NULL)
	return (0);

	size_t left_nodes = binary_tree_nodes(tree->left);
	size_t right_nodes = binary_tree_nodes(tree->right);

	return (1 + left_nodes + right_nodes);
}
