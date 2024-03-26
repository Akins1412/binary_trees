#include "binary_trees.h"

int _binary_tree_height(const binary_tree_t *tree);
void _func_on_level(const binary_tree_t *tree, int level, void (*func)(int));

/**
 * binary_tree_levelorder - goes through a binary tree using
 *+ level-order traversal
 *
 * @tree: a ptr to the root node of the tree to traverse.
 * @func: a ptr to the function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int tree_height, j;

	if (tree == NULL || func == NULL)
		return;

	/*Get tree height*/
	tree_height = _binary_tree_height(tree);

	/*Iterate levels till you reach the height*/
	for (j = 1; j <= tree_height; j++)
	{
		/*Call the function on each level*/
		_func_on_level(tree, j, func);
	}
}

/**
 * _binary_tree_height - measures the height of a binary tree
 *
 * @tree: a ptr to the root node of the tree to find height.
 * Return: height of the tree or 0 if tree is NULL.
 */
int _binary_tree_height(const binary_tree_t *tree)
{
	int lft_ht = 0, rgt_ht = 0;

	if (tree == NULL)
	{
		return (0);
	}

	/*Recursively call the func to calc. the height*/
	lft_ht = _binary_tree_height(tree->left);
	rgt_ht = _binary_tree_height(tree->right);

	/*Compare for the maximum depth*/
	if (lft_ht > rgt_ht)
		return (lft_ht + 1);
	return (rgt_ht + 1);
}

/**
 * _func_on_level - calls a given function on a level of the binary tree.
 *
 * @tree: ptr to the root of the binary tree.
 * @level: the level to call the function.
 * @func: the function to call.
 */

void _func_on_level(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (tree == NULL)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		/*Call the function recursively*/
		_func_on_level(tree->left, level - 1, func);
		_func_on_level(tree->right, level - 1, func);
	}
}
