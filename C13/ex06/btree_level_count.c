/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by msmiesko          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

static int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	btree_level_count(t_btree *root)
{
	int	left_count;
	int	right_count;

	if (root == NULL)
		return (0);
	left_count = btree_level_count(root->left);
	right_count = btree_level_count(root->right);
	return (1 + max(left_count, right_count));
}

/*
int main(void)
{
	t_btree	root;
	t_btree	left;
	int		a;
	int		b;

	a = 1;
	b = 2;
	root.item = &a;
	root.left = &left;
	root.right = NULL;
	left.item = &b;
	left.left = NULL;
	left.right = NULL;
	return (btree_level_count(&root));
}
*/
