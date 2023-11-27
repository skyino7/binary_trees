#include "binary_trees.h"

/**
 * binary_tree_insert_left - binary tree insert
 * @parent: parent node
 * @value: value
 * Return: Null or left child node
*/

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	if (parent == NULL)
		return (NULL);

	binary_tree_t *left_chld = malloc(sizeof(binary_tree_t));

	if (left_chld == NULL)
		return (NULL);

	left_chld->n = value;
	left_chld->parent = parent;
	left_chld->left = parent->left;
	left_chld->right = NULL;

	parent->left = left_chld;

	if (left_chld->left != NULL)
		left_chld->left->parent = left_chld;

	return (left_chld);
}
