#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree.
 *
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *indict, *tem;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	indict = tree->left;
	tem = indict->right;
	indict->right = tree;
	tree->left = tem;
	if (tem != NULL)
		tem->parent = tree;
	tem = tree->parent;
	tree->parent = indict;
	indict->parent = tem;
	if (tem != NULL)
	{
		if (tem->left == tree)
			tem->left = indict;
		else
			tem->right = indict;
	}

	return (indict);
}
