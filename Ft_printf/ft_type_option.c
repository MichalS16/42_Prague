/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:20:54 by msmiesko          #+#    #+#             */
/*   Updated: 2024/04/13 14:20:54 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type_option(char type, va_list args, int *len)
{
	if (type == 'd' || type == 'i')
		ft_putnbr(va_arg(args, int), len);

	if (type == 'u')
		ft_putnbr(va_arg(args, unsigned int), len);

	else if (type == 'c')
		ft_putchar_len((unsigned char) va_arg(args, int), len);

	else if (type == 's')
		ft_putstr_len(va_arg(args, void *), len);

	else if (type == 'x')
		ft_puthexa(va_arg(args, int), 'h', len);

	else if (type == 'X')
		ft_puthexa(va_arg(args, int), 'H', len);

	else if (type == 'p')
		ft_putpointer(va_arg(args, void *), len);

	else if (type == '%')
		ft_putchar_len('%', len);

	return;
}
