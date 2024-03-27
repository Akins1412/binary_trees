#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree.
 *
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node of the tree once rotated.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{

	binary_tree_t *indict, *tem;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	indict = tree->right;
	tem = indict->left;
	indict->left = tree;
	tree->right = tem;
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
