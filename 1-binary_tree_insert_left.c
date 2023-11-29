#include "binary_trees.h"

/**
 * binary_tree_insert_left - binary tree insert
 * @parent: parent node
 * @value: value
 * Return: Null or left child insert node
*/

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	if (parent == NULL)
		return (NULL);

	binary_tree_t *left_child = malloc(sizeof(binary_tree_t));

	if (left_child == NULL)
		return (NULL);

	left_child->n = value;
	left_child->parent = parent;
	left_child->left = parent->left;
	left_child->right = NULL;

	parent->left = left_child;

	if (left_child->left != NULL)
		left_child->left->parent = left_child;

	return (left_child);
}
