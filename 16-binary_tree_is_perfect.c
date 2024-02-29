#include <stdlib.h>
#include <stdbool.h>
#include "binary_trees.h"

/**
 * binary_tree_height - Function measures the height of a binary tree
 * @tree :  pointer to the root node of the tree to measure the height
 * Return: height of tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t hleft, hright;

	if (tree == NULL)
		return (0);

	hleft = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	hright = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (hleft > hright ? hleft : hright);
}

/**
 * binary_tree_depth - Function measures the height of a binary tree
 * @tree :  pointer to the root node of the tree to measure the depth
 * Return: depth of tree
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth;

	if (tree == NULL)
		return (0);
	depth = tree->parent ? 1 + binary_tree_depth(tree->parent) : 0;
	return (depth);
}

/**
 * is_pt_leaf - Function checks if a node is a leaf of perfect tree (pt)
 * @node :  pointer to the node to check
 * @height : main tree height
 * Return: True if node is a pt leaf, otherwise False
 */
bool is_pt_leaf(const binary_tree_t *node, size_t height)
{
	size_t depth;

	depth = binary_tree_depth(node);
	if ((node->left == NULL && node->right == NULL) &&
		(depth == height))
	{
		return (true);
	}
	else
		return (false);
}

/**
 * bperfect - function checks if a binary tree is full
 * @tree : pointer to the root node of the tree to check
 * @n : count
 * @height : height of main tree
 * Return: 1 if full and 0 otherwise
 */
int bperfect(const binary_tree_t *tree, int n, size_t height)
{
	int ret = n;

	if (tree == NULL)
		return (ret);

	if (!(is_pt_leaf(tree, height)) && !(tree->left != NULL &&
		tree->right != NULL))
	{
		++ret;
		return (ret);
	}
	ret = bperfect(tree->left, ret, height);
	ret = bperfect(tree->right, ret, height);

	return (ret);
}

/**
 * binary_tree_is_perfect - function checks if a binary tree is perfect
 * @tree : pointer to the root node of the tree to check
 * Return: 1 if full and 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height;
	int n, count = 0;

	if (tree == NULL)
		return (0);
	height = binary_tree_height(tree);

	n = bperfect(tree, count, height);
	if (n > 0)
		return (0);
	return (1);
}
