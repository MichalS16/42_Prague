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

void	ft_put_hexa_adress(uintptr_t number, int *len)
{
	char	base[17];

	ft_strlcpy(base, "0123456789abcdef", 17);
	if (number > 15)
	{
		ft_put_hexa_adress(number / 16, len);
		ft_put_hexa_adress(number % 16, len);
	}
	else
		ft_putchar_len(base[number], len);
}

void	ft_putpointer(void *ptr, int *len)
{
	if (ptr == NULL)
	{
		ft_putstr_len("(nil)", len);
		return ;
	}
	ft_putstr_len("0x", len);
	ft_put_hexa_adress((uintptr_t) ptr, len);
}
