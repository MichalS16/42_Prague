/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by msmiesko          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
			int (*cmpf)(void *, void *))
{
	void	*result;

	if (root == NULL)
		return (NULL);
	result = btree_search_item(root->left, data_ref, cmpf);
	if (result != NULL)
		return (result);
	if (cmpf(root->item, data_ref) == 0)
		return (root->item);
	return (btree_search_item(root->right, data_ref, cmpf));
}

/*
static int	cmp_int(void *a, void *b)
{
	return (*(int *)a - *(int *)b);
}

int main(void)
{
	t_btree	root;
	int		a;
	int		ref;
	void	*found;

	a = 42;
	ref = 42;
	root.item = &a;
	root.left = NULL;
	root.right = NULL;
	found = btree_search_item(&root, &ref, cmp_int);
	return (found == NULL);
}
*/
