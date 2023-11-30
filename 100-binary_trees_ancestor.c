#include "binary_trees.h"

/**
 * binary_tree_depth - measures depth
 * @tree: tree
 * Return: depth or NULL
*/

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree != NULL)
	{
		depth++;
		tree = tree->parent;
	}

	return (depth);

}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: first node
 * @second: second node
 * Return: lowest common ancestor or NULL
*/

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
const binary_tree_t *second)
{
	size_t d_first, d_second;

	if (first == NULL || second == NULL)
		return (NULL);

	d_first = binary_tree_depth(first);
	d_second = binary_tree_depth(second);

	while (d_first > d_second)
	{
		first = first->parent;
		d_first--;
	}

	while (d_second > d_first)
	{
		second = second->parent;
		d_second--;
	}

	while (first != NULL && second != NULL)
	{
		if (first == second)
			return ((binary_tree_t *)first);

		first = first->parent;
		second = second->parent;
	}

	return (NULL);

}
