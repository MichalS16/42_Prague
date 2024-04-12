/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 23:29:14 by msmiesko          #+#    #+#             */
/*   Updated: 2024/04/12 23:29:14 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr(uintptr_t nbr)
{
	char	*string;
	int		value;

	value = 0;
	string = "0123456789abcdef";
	if (nbr >= 16)
	{
		value += ft_putptr(nbr / 16);
		value += ft_putptr(nbr % 16);
	}
	else
		value += write(1, &string[nbr], 1);
	return (value);
}

int	ft_printptr(unsigned long long ptr)
{
	int	value;

	value = 0;
	if (!ptr)
		value += write(1, "(nil)", 5);
	else
	{
		value += ft_printstr("0x");
		value += ft_putptr(ptr);
	}
	return (value);
}