#include <stdlib.h>
#include <stdbool.h>
#include "binary_trees.h"

/**
 * bt_is_leaf - Function checks if a node is a leaf
 * @node :  pointer to the node to check
 * Return: True if node is a leaf, otherwise False
 */
bool bt_is_leaf(const binary_tree_t *node)
{
	if (node->left == NULL && node->right == NULL)
		return (true);
	else
		return (false);
}

/**
 * has_two_children - checks if node has both left and right offsprings
 * @node : pointer to the node to check
 * Return: 1 if node has two children, otherwise 0
 */
bool has_two_children(const binary_tree_t *node)
{
	if (node->left != NULL && node->right != NULL)
		return (true);
	else
		return (false);
}

/**
 * bfull - function checks if a binary tree is full
 * @tree : pointer to the root node of the tree to check
 * @n : count
 * Return: 1 if full and 0 otherwise
 */
int bfull(const binary_tree_t *tree, int n)
{
	int ret = n;

	if (tree == NULL)
		return (ret);

	if (!(bt_is_leaf(tree)) && !(has_two_children(tree)))
	{
		++ret;
		return (ret);
	}
	ret = bfull(tree->left, ret);
	ret = bfull(tree->right, ret);

	return (ret);
}

/**
 * binary_tree_is_full - function checks if a binary tree is full
 * @tree : pointer to the root node of the tree to check
 * Return: 1 if full and 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int n;

	if (tree == NULL)
		return (0);

	n = bfull(tree, 0);
	if (n > 0)
		return (0);
	return (1);
}
