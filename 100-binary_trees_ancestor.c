#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the least common ancestor of two nodes.
 *
 * @first: points to the first node.
 * @second: points to the second node.
 *
 * Return: points to the least common ancestor node of the two given nodes.
 *         If no common ancestor was found, your function must return NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *p1, *p2;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	p1 = first->parent, p2 = second->parent;
	if (first == p2 || !p1 || (!p1->parent && p2))
		return (binary_trees_ancestor(first, p2));
	else if (p1 == second || !p2 || (!p2->parent && p1))
		return (binary_trees_ancestor(p1, second));

	return (binary_trees_ancestor(p1, p2));
}
