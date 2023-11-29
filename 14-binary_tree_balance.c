#include "binary_trees.h"

/**
 * tree_height - helper measures the height of a binary tree
 * @tree: tree
 * Return: 0 or height of tree
*/

size_t tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = tree_height(tree->left);
	right = tree_height(tree->right);

	return (left > right ? left + 1 : right + 1);

}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree
 * Return: 0 or height of the tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	return (tree_height(tree) - 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: tree
 * Return: balance factor of the tree, 0 if tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left, right, sum = 0;

	if (tree == NULL)
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);
	sum = left - right;

	return (sum);
}
