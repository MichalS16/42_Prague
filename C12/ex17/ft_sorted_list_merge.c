/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 12:00:00 by msmiesko          #+#    #+#             */
/*   Updated: 2026/07/27 12:00:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>

static t_list	*ft_pop_smallest(t_list **list1, t_list **list2,
		int (*cmp)(void *, void *))
{
	t_list	*node;

	if (*list1 == NULL)
	{
		node = *list2;
		*list2 = (*list2)->next;
	}
	else if (*list2 == NULL)
	{
		node = *list1;
		*list1 = (*list1)->next;
	}
	else if (cmp((*list1)->data, (*list2)->data) <= 0)
	{
		node = *list1;
		*list1 = (*list1)->next;
	}
	else
	{
		node = *list2;
		*list2 = (*list2)->next;
	}
	return (node);
}

static t_list	*ft_merge_loop(t_list **list1, t_list *list2,
		int (*cmp)(void *, void *))
{
	t_list	*result;
	t_list	*tail;

	result = NULL;
	tail = NULL;
	while (*list1 != NULL || list2 != NULL)
	{
		if (result == NULL)
		{
			result = ft_pop_smallest(list1, &list2, cmp);
			tail = result;
		}
		else
		{
			tail->next = ft_pop_smallest(list1, &list2, cmp);
			tail = tail->next;
		}
	}
	tail->next = NULL;
	return (result);
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)(void *, void *))
{
	if (*begin_list1 == NULL)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	if (begin_list2 == NULL)
		return ;
	*begin_list1 = ft_merge_loop(begin_list1, begin_list2, cmp);
}
