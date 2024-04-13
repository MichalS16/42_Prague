/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:51:54 by msmiesko          #+#    #+#             */
/*   Updated: 2024/04/13 14:51:54 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putpointer(void *ptr, int *len)
{
	if (ptr == NULL)
	{
		ft_putstr_len("(nil)", len);
		return;
	}

	ft_putstr_len("0x", len);
	ft_puthexa((uintptr_t) ptr, len);
}
