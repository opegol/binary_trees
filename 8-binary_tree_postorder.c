#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_postorder - Function goes through a binary tree
 *			using post-order traversal
 * @tree : pointer to the root node of the tree to traverse
 * @func : pointer to a function to call for each node
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *tmleft, *tmright;

	if (tree == NULL || func == NULL)
		return;
	tmleft = tree->left;
	tmright = tree->right;
	binary_tree_postorder(tmleft, func);
	binary_tree_postorder(tmright, func);
	func(tree->n);
}
