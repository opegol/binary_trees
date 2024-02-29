#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * one_or_more_child - Function checks if a node is a has at least a child
 * @node :  pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0
 */
int one_or_more_child(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->left != NULL || node->right != NULL)
		return (1);
	else
		return (0);
}

/**
 * child_count - Function counts nodes with at least a child
 * @tree : pointer to the root node of the tree
 * @n : count
 * Return: required count
 */
size_t child_count(const binary_tree_t *tree, size_t n)
{
	size_t count = n;

	if (tree == NULL)
		return (count);
	if (one_or_more_child(tree) == 1)
		++count;
	count = child_count(tree->left, count);
	count = child_count(tree->right, count);
	return (count);
}

/**
 * binary_tree_nodes - Function counts the nodes with
 *			at least 1 child in a binary tree
 * @tree : pointer to the root node of the tree to count the number of nodes
 * Return: the count of at least 1 child nodes
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t n;

	n = child_count(tree, 0);
	return (n);
}
