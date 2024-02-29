#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_delete - Function deletes an entire binary tree
 * @tree :  pointer to the root node of the tree to delete
 */
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *tmleft, *tmright;

	if (tree == NULL)
		return;
	tmleft = tree->left;
	tmright = tree->right;
	free(tree);
	binary_tree_delete(tmleft);
	binary_tree_delete(tmright);
}
