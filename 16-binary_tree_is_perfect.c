#include "binary_trees.h"

/**
 * binary_tree_size -  measures the size of a binary tree
 * @tree: tree
 * Return: size of tree
*/

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = binary_tree_size(tree->left);
	right = binary_tree_size(tree->right);

	return (left + right + 1);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: tree
 * Return: 0 or height of tree
*/

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left, right;

	if (tree == NULL)
		return (0);

	left = binary_tree_height(tree->left);
	right = binary_tree_height(tree->right);

	return (left > right ? left + 1 : right + 1);

}

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: tree
 * Return: 1 or 0
*/

int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	if (tree->left != NULL && tree->right != NULL)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));

	return (0);
}

/**
 * binary_tree_is_perfect -  checks if a binary tree is perfect
 * @tree: tree
 * Return: 0 or 1
*/

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, size;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	size = binary_tree_size(tree);
	return (binary_tree_is_full(tree) && ((size_t)(1 << height) - 1 == size));

}
