#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inputs node as the left-child of a different node.
 * @parent: Points to the node to input the left child in.
 * @value: The value to store a new node.
 * Return: A pointer to the created node [SUCCESS], NULL on failure.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *lft_child;

	if (parent == NULL)
		return (NULL);

	lft_child = binary_tree_node(parent, value);
	if (lft_child == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		lft_child->left = parent->left;
		parent->left->parent = lft_child;
	}
	parent->left = lft_child;

	return (lft_child);
}
