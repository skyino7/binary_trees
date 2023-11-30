#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: binary tree
 * Return: 0 or height of tree
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree != NULL)
	{
		left = binary_tree_height(tree->left);
		right = binary_tree_height(tree->right);

		return ((MAX(left, right)) + (tree->left || tree->right ? 1 : 0));
	}

	return (0);
}
