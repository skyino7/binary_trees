#include "binary_trees.h"

/**
 * binary_tree_insert_right - binary tree right insert
 * @parent: parent node
 * @value: value
 * Return: Null or left child insert node
*/

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	if (parent == NULL)
		return (NULL);

	binary_tree_t *right_child = malloc(sizeof(binary_tree_t));

	if (right_child == NULL)
		return (NULL);

	right_child->n = value;
	right_child->parent = parent;
	right_child->right = parent->right;
	right_child->right = NULL;

	parent->right = right_child;

	if (right_child->right != NULL)
		right_child->right->parent = right_child;

	return (right_child);
}
