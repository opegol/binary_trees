#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_uncle - finds the uncle of a node
 * @node : pointer to the node to find the uncle
 * Return: pointer to the sibling node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *n;

	if (!(node) || !(node->parent) || !(node->parent->parent))
		return (NULL);
	n = node->parent;
	if (n == n->parent->left)
		return (n->parent->right);
	else if (n == n->parent->right)
		return (n->parent->left);
	return (NULL);
}

