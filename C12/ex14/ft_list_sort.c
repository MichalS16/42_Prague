/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 12:00:00 by msmiesko          #+#    #+#             */
/*   Updated: 2026/07/27 12:00:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>

static void	ft_swap_data(t_list *list_ptr, t_list *list_other_ptr)
{
	void	*tmp;

	tmp = list_ptr->data;
	list_ptr->data = list_other_ptr->data;
	list_other_ptr->data = tmp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)(void *, void *))
{
	t_list	*list_ptr;
	t_list	*list_other_ptr;

	if (*begin_list == NULL)
		return ;
	list_ptr = *begin_list;
	while (list_ptr != NULL)
	{
		list_other_ptr = list_ptr->next;
		while (list_other_ptr != NULL)
		{
			if (cmp(list_ptr->data, list_other_ptr->data) > 0)
				ft_swap_data(list_ptr, list_other_ptr);
			list_other_ptr = list_other_ptr->next;
		}
		list_ptr = list_ptr->next;
	}
}
