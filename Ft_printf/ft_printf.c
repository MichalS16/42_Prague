/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:49:35 by msmiesko          #+#    #+#             */
/*   Updated: 2024/04/13 14:49:35 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		sum;
	int		*len;

	va_start(args, str);
	sum = 0;
	len = &sum;
	while (*str)
	{
		if (*str != '%')
			ft_putchar_len(*str, len);

		else
		{
			ft_type_option(*(str + 1), args, len);
			str++;
		}
		str++;
	}
	va_end(args);
	return (sum);
}