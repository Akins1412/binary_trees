#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 *
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *active, *current;

	if (tree != NULL)
	{
		active = *tree;
		if (active == NULL)
		{
			current = binary_tree_node(active, value);
			if (current == NULL)
				return (NULL);
			return (*tree = current);
		}
		if (value < active->n)
		{
			if (active->left != NULL)
				return (bst_insert(&active->left, value));
			current = binary_tree_node(active, value);
			if (current == NULL)
				return (NULL);
			return (active->left = current);
		}
		if (value > active->n)
		{
			if (active->right != NULL)
				return (bst_insert(&active->right, value));
			current = binary_tree_node(active, value);
			if (current == NULL)
				return (NULL);
			return (active->right = current);
		}
	}

	return (NULL);
}
