/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by msmiesko          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

static t_queue	*queue_new(t_btree *node, int level)
{
	t_queue	*elem;

	elem = malloc(sizeof(t_queue));
	if (elem == NULL)
		return (NULL);
	elem->node = node;
	elem->level = level;
	elem->next = NULL;
	return (elem);
}

static void	queue_push(t_queue **head, t_queue **tail, t_btree *node,
			int level)
{
	t_queue	*elem;

	if (node == NULL)
		return ;
	elem = queue_new(node, level);
	if (elem == NULL)
		return ;
	if (*head == NULL)
	{
		*head = elem;
		*tail = elem;
		return ;
	}
	(*tail)->next = elem;
	*tail = elem;
}

void	btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
			int current_level, int is_first))
{
	t_queue	*head;
	t_queue	*tail;
	t_queue	*tmp;
	int		last_level;

	if (root == NULL)
		return ;
	head = NULL;
	tail = NULL;
	queue_push(&head, &tail, root, 0);
	last_level = -1;
	while (head != NULL)
	{
		applyf(head->node->item, head->level, head->level != last_level);
		last_level = head->level;
		queue_push(&head, &tail, head->node->left, head->level + 1);
		queue_push(&head, &tail, head->node->right, head->level + 1);
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

/*
#include <stdio.h>

static void	print_item(void *item, int current_level, int is_first)
{
	if (is_first)
		printf("\n[%d] ", current_level);
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
	btree_apply_by_level(&root, print_item);
	return (0);
}
*/
