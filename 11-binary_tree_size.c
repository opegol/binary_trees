#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"


/**
 * node_count - Function counts the nodes of a binary tree
 * @tree : pointer to the root node of the tree to measure the size
 * Return: the size of the tree
 */
size_t node_count(const binary_tree_t *tree)
{
	size_t sleft, sright;

	if (tree == NULL)
		return (0);
	sleft = 1 + node_count(tree->left);
	sright = 1 + node_count(tree->right);
	return (sleft + sright);
}

/**
 * binary_tree_size - Function measures the size of a binary tree
 * @tree : pointer to the root node of the tree to measure the size
 * Return: the size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t n;

	n = node_count(tree);
	return (n / 2);
}
