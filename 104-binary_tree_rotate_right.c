#include "binary_trees.h"

/**
 * binary_tree_rotate_right - a right-rotation on a binary tree
 * @tree: tree
 * Return: new root node of tree rotated
*/

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *root, *tmp;

	if (tree == NULL || tree->left == NULL)
		return (tree);

	root = tree->left;
	tmp = root->right;

	root->right = tree;
	tree->left = tmp;

	if (tmp != NULL)
		tmp->parent = tree;

	root->parent = tree->parent;
	tree->parent = root;

	return (root);

}
