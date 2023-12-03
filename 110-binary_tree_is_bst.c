#include "binary_trees.h"

/**
 * is_helper - helper
 * @node: node
 * @min: min value
 * @max: max value
 * Return: 1 or 0
*/

int is_helper(const binary_tree_t *node, int min, int max)
{
	int left, right;

	if (node == NULL)
		return (1);

	if (node->n <= min || node->n >= max)
		return (0);

	left = is_helper(node->left, min, node->n);
	right = is_helper(node->right, node->n, max);

	return (left && right);

}

/**
 * binary_tree_is_bst - binary is a valid BST
 * @tree: tree
 * Return: 1 or 0
*/

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_helper(tree, INT_MIN, INT_MAX));
}
