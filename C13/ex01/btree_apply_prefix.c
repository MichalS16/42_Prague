/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_prefix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by msmiesko          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL)
		return ;
	applyf(root->item);
	btree_apply_prefix(root->left, applyf);
	btree_apply_prefix(root->right, applyf);
}

/*
#include <stdio.h>

static void	print_int(void *item)
{
	printf("%d ", *(int *)item);
}

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
	btree_apply_prefix(&root, print_int);
	return (0);
}
*/
