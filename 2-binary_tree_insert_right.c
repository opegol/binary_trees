#include <stdlib.h>
#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_insert_right - Function inserts a node as the
 *				right-child of another node
 * @parent : pointer to the node to insert the right-child in
 * @value : value to put in the new node
 * Return: pointer to created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new, *tmp;

	if (parent == NULL)
		return (NULL);
	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	(*new).n = value;
	if ((parent->right) != NULL)
	{
		tmp = parent->right;
		new->right = tmp;
		parent->right = new;
		tmp->parent = new;
	}
	else
		parent->right = new;

	return (new);
}

