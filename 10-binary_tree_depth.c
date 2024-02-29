#include <stdlib.h>
#include "binary_trees.h"

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
