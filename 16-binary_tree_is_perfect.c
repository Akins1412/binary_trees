#include "binary_trees.h"

int _binary_tree_size(const binary_tree_t *tree);
int _binary_tree_is_full(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - checking if a binary tree is ok.
 *
 * @tree: points to the root node of the tree to check
 * Return: 1 - if Perfect, 0 - if Not Perfect or tree is NULL
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int lft_chl_sze, rgt_chl_sze, rgt_chld_ful, lft_chld_ful;
	int siz_chec = 0, ful_chec = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	lft_chl_sze = _binary_tree_size(tree->left);
	rgt_chl_sze = _binary_tree_size(tree->right);
	if (lft_chl_sze == rgt_chl_sze)
		siz_chec = 1;

	rgt_chld_ful = _binary_tree_is_full(tree->left);
	lft_chld_ful = _binary_tree_is_full(tree->right);
	if (rgt_chld_ful == 1 && lft_chld_ful == 1)
		ful_chec = 1;

	if (siz_chec == 1 && ful_chec == 1)
		return (1);

	return (0);
}

/**
 * _binary_tree_size - measuring the size of a binary tree.
 *
 * @tree: points to the root node of the tree to measure.
 * Return: 0 if tree is NULL.
*/
int _binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
	return (0);

	size_t left_size = _binary_tree_size(tree->left);
	size_t right_size = _binary_tree_size(tree->right);

	return (1 + left_size + right_size);
}

/**
 * _binary_tree_is_full - checks if a binary tree is full.
 *
 * @tree: ptr to the root node of the tree to check.
 * Return: 1 - tree isFull, 0 - tree isNotFull or NULL.
 */
int _binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if ((tree->left != NULL) && (tree->right != NULL))
	{
		return (_binary_tree_is_full(tree->left) &&
				_binary_tree_is_full(tree->right));
	}

	if ((tree->left == NULL && tree->right == NULL))
	{
		return (1);
	}

	return (0);
}
