#include "binary_trees.h"


/**
 * binary_tree_node - Opens up a new binary tree node.
 * @parent: points to the parent node.
 * @value: the value to put in the new node.
 * Return: points to the created node - SUCCESS or NULL - FAILURE
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *recent;

	recent = malloc(sizeof(binary_tree_t));
	if (recent == NULL)
		return (NULL);

	recent->n = value;
	recent->parent = parent;
	recent->left = NULL;
	recent->right = NULL;

	return (recent);
}
