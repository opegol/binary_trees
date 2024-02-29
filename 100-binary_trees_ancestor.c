#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first : pointer to the first node
 * @second : pointer to the second node
 * Return: pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)

{
	const binary_tree_t *tmp;

	if (!first || !second)
		return (NULL);

	while (first)
	{
		tmp = second;
		while (tmp)
		{
			if (first == tmp)
				return ((binary_tree_t *)first);
			tmp = tmp->parent;
		}
		first = first->parent;
	}
	return (NULL);
}
