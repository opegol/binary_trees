#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_preorder - Function goes through a binary tree
 *			using pre-order traversal
 * @tree : pointer to the root node of the tree to traverse
 * @func : pointer to a function to call for each node
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *tmleft, *tmright;

	if (tree == NULL)
		return;
	tmleft = tree->left;
	tmright = tree->right;
	func(tree->n);
	binary_tree_preorder(tmleft, func);
	binary_tree_preorder(tmright, func);
}
