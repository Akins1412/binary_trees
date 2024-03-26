#include "binary_trees.h"

/**
 * binary_tree_postorder - passes through bina tree using pre-order traversal.
 *
 * @tree: a pointer to the root node of the tree to traverse it
 * @func: points to function to call for each node. the value in the node
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!(tree != NULL && func != NULL))
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);

	/*Apply function to current node.*/
	func(tree->n);
}
