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
 * binary_tree_levelorder - a binary tree using level-order traversal
 * @tree: tree
 * @func: function pointer
*/

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue, *curr;
	size_t front = 0, rear = 0;

	if (tree == NULL || func == NULL)
		return;

	queue = malloc(sizeof(binary_tree_t *) * binary_tree_size(tree));

	if (queue == NULL)
		return;

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		curr = queue[front++];
		func(curr->n);

		if (curr->left != NULL)
			queue[rear++] = curr->left;

		if (curr->right != NULL)
			queue[rear++] = curr->right;
	}
	free(queue);
}
