#include "binary_trees.h"
#include <stdio.h>

int _binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_balance - measuring the balance factor of a binary tree.
 *
 * @tree: pointer to the root node of the tree to measure bin. factor
 * Return: 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int lft, rgt;

	if (tree == NULL)
		return (0);

	lft = _binary_tree_height(tree->lft);
	rgt = _binary_tree_height(tree->rgt);

	return (lft - rgt);
}


/**
 * _binary_tree_height - measuring the height of a binary tree
 *
 * @tree: a pointer to the root node of the tree to find height.
 * Return: 0 if tree is NULL
 */
int _binary_tree_height(const binary_tree_t *tree)
{
	int lft_t = 0;
	int rgt_t = 0;

	if (tree == NULL)
		return (-1);

	if (tree->lft == NULL && tree->rgt == NULL)
		return (0);

	lft_t = _binary_tree_height(tree->lft);
	rgt_t = _binary_tree_height(tree->rgt);

	if (lft_t > rgt_t)
		return (lft_t + 1);
	return (rgt_t + 1);
}
