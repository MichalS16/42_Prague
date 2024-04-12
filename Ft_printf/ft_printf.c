/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 23:30:38 by msmiesko          #+#    #+#             */
/*   Updated: 2024/04/12 23:30:38 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_selection(va_list args, char detecter)
{
	int	output;

	output = 0;
	if (detecter == 'c')
		output = ft_printchar(va_arg(args, int));
	else if (detecter == 's')
		output = ft_printstr(va_arg(args, char *));
	else if (detecter == 'p')
		output = ft_printptr(va_arg(args, unsigned long long));
	else if (detecter == 'd' || detecter == 'i')
		output = ft_printnbr(va_arg(args, int), 10, 0);
	else if (detecter == 'u')
		output = ft_printnbr(va_arg(args, unsigned int), 10, 0);
	else if (detecter == 'x')
		output = ft_printnbr(va_arg(args, unsigned int), 16, 0);
	else if (detecter == 'X')
		output = ft_printnbr(va_arg(args, unsigned int), 16, 1);
	else if (detecter == '%')
		output = ft_printchar('%');
	else
		output = ft_printstr("There is an error, please check again");
	return (output);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		output;

	i = 0;
	output = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			output += ft_selection(args, str[i + 1]);
			i++;
		}
		else
			output += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (output);
}