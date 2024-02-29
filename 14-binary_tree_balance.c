#include <stdlib.h>
#include "binary_trees.h"

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

	hleft = tree->left ? 1 + binary_tree_balance(tree->left) : 0;
	hright = tree->right ? 1 + binary_tree_balance(tree->right) : 0;
	return (hleft - hright);
}
