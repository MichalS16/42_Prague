/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:35:46 by msmiesko          #+#    #+#             */
/*   Updated: 2024/04/13 14:35:46 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_len(char *str, int *len)
{
	if (str == NULL)
	{
		ft_ft_putstr_len("(null)", len);
		return;
	}

	while (*str)
	{
		write(1, str++, 1);
		(*len)++;
	}
}
