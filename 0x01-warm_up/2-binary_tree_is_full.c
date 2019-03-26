#include "binary_trees.h"

/**
 * binary_tree_is_full - tree checker
 * @binary_tree_t: pointer to tree node or parent node
 *
 * Description: check if full tree
 * Return: 0 if tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left && tree->right == NULL)
		return (0);

	if (tree->right && tree->left == NULL)
		return (0);

	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right));
	return (1);
}
