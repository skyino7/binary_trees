#include "binary_trees.h"

/**
 * binary_tree_rotate_left - a left-rotation on a binary tree
 * @tree: tree
 * Return: new root node of tree rotated
*/

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *root, *tmp;

	if (tree == NULL || tree->right == NULL)
		return (tree);

	root = tree->right;
	tmp = root->left;

	root->left = tree;
	tree->right = tmp;

	if (tmp != NULL)
		tmp->parent = tree;

	root->parent = tree->parent;
	tree->parent = root;

	return (root);
}
