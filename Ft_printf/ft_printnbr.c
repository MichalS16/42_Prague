/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 23:29:59 by msmiesko          #+#    #+#             */
/*   Updated: 2024/04/12 23:29:59 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(long n, int base, int uppercase)
{
	int			output;
	const char	*string;

	output = 0;
	if (n < 0)
	{
		output += write(1, "-", 1);
		output += ft_printnbr(-n, base, uppercase);
	}
	else if (n < base)
	{
		if (uppercase)
			string = "0123456789ABCDEF";
		else
			string = "0123456789abcdef";
		return (output += write(1, &string[n], 1));
	}
	else
	{
		output += ft_printnbr(n / base, base, uppercase);
		output += ft_printnbr(n % base, base, uppercase);
	}
	return (output);
}