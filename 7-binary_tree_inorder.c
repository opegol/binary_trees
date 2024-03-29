#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_inorder - Function goes through a binary tree
 *			using in-order traversal
 * @tree : pointer to the root node of the tree to traverse
 * @func : pointer to a function to call for each node
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *tmleft, *tmright;

	if (tree == NULL || func == NULL)
		return;
	tmleft = tree->left;
	tmright = tree->right;
	binary_tree_inorder(tmleft, func);
	func(tree->n);
	binary_tree_inorder(tmright, func);
}
