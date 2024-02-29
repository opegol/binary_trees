#include <stdlib.h>
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
