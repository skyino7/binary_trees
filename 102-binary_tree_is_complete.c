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
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: tree
 * Return: 1 or 0
*/

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int level = 0;
	binary_tree_t **queue, *curr;
	size_t front = 0, rear = 0;

	if (tree == NULL)
		return (0);

	queue = malloc(sizeof(binary_tree_t *) * binary_tree_size(tree));

	if (queue == NULL)
		return (0);

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		curr = queue[front++];

		if (level && (curr->left != NULL || curr->right != NULL))
		{
			free(queue);
			return (0);
		}

		if (curr->left == NULL || curr->right == NULL)
			level = 1;

		if (curr->left != NULL)
			queue[rear++] = curr->left;

		if (curr->right != NULL)
			queue[rear++] = curr->right;
	}

	free(queue);

	return (1);
}
