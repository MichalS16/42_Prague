/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 12:00:00 by msmiesko          #+#    #+#             */
/*   Updated: 2026/07/27 12:00:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>

static int	ft_list_len(t_list *begin_list)
{
	int	count;

	count = 0;
	while (begin_list != NULL)
	{
		count++;
		begin_list = begin_list->next;
	}
	return (count);
}

static t_list	*ft_list_node_at(t_list *begin_list, int nbr)
{
	while (nbr > 0)
	{
		begin_list = begin_list->next;
		nbr--;
	}
	return (begin_list);
}

static void	ft_swap_nodes(t_list *left, t_list *right)
{
	void	*tmp;

	tmp = left->data;
	left->data = right->data;
	right->data = tmp;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int	size;
	int	lo;
	int	hi;

	size = ft_list_len(begin_list);
	lo = 0;
	hi = size - 1;
	while (lo < hi)
	{
		ft_swap_nodes(ft_list_node_at(begin_list, lo),
			ft_list_node_at(begin_list, hi));
		lo++;
		hi--;
	}
}
