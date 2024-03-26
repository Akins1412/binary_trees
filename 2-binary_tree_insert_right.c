#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a nodes as the right-child.
 * @parent: Points to the node to input the right-child in.
 * @value: The value to store a new node.
 *
 * Return: A pointer to the created node [SUCCESS], NULL on failure.
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *rgt_child;

	if (parent == NULL)
		return (NULL);

	rgt_child = binary_tree_node(parent, value);
	if (rgt_child == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		rgt_child->right = parent->right;
		parent->right->parent = rgt_child;
	}
	parent->right = rgt_child;

	return (rgt_child);
}
