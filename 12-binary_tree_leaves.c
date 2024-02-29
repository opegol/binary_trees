#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_is_leaf - Function checks if a node is a leaf
 * @node :  pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->left == NULL && node->right == NULL)
		return (1);
	else
		return (0);
}

/**
 * leaf_count - Function counts the leaves of a binary tree
 * @tree : pointer to the root node of the tree to measure the size
 * @n : leaf count
 * Return: the size of the tree
 */
size_t leaf_count(const binary_tree_t *tree, size_t n)
{
	size_t count = n;

	if (tree == NULL)
		return (count);
	if (binary_tree_is_leaf(tree) == 1)
		++count;
	count = leaf_count(tree->left, count);
	count = leaf_count(tree->right, count);
	return (count);
}

/**
 * binary_tree_leaves - Function returns the count of leaves in a binary tree
 * @tree : pointer to the root node of the tree to measure the size
 * Return: the size of the tree
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t n;

	n = leaf_count(tree, 0);
	return (n);
}
