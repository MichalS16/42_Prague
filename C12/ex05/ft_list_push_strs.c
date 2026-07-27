/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 12:00:00 by msmiesko          #+#    #+#             */
/*   Updated: 2026/07/27 12:00:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*begin_list;
	t_list	*first;
	t_list	*elem;
	int		i;

	begin_list = NULL;
	first = NULL;
	i = 0;
	while (i < size)
	{
		elem = ft_create_elem(strs[i]);
		if (elem == NULL)
			return (first);
		if (i == 0)
			first = elem;
		elem->next = begin_list;
		begin_list = elem;
		i++;
	}
	return (first);
}
