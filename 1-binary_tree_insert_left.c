#include <stdlib.h>
#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_insert_left - Function inserts a node as the
 *				left-child of another node
 * @parent : pointer to the node to insert the left-child in
 * @value : value to put in the new node
 * Return: pointer to created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
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
	if ((parent->left) != NULL)
	{
		tmp = parent->left;
		new->left = parent->left;
		parent->left = new;
		tmp->parent = new;
	}
	else
		parent->left = new;

	return (new);
}

