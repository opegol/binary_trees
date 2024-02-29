#include <stdlib.h>
#include <stdio.h>
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
 * binary_tree_balance - Function measures the balance factor of a binary tree
 * @tree :  pointer to the root node of the tree to measure the alance factor
 * Return: balance factor of tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t hleft, hright;

	if (tree == NULL)
		return (0);
	if (!tree->left)
		hleft = 0;
	else
		hleft = 1 + binary_tree_height(tree->left);
	if (!tree->right)
		hright = 0;
	else
		hright = 1 + binary_tree_height(tree->right);
	return (hleft - hright);
}
