/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:46:29 by msmiesko          #+#    #+#             */
/*   Updated: 2024/04/13 14:46:29 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthexa(unsigned int number, char hex_base, int *len)
{
	char	base[17];

	if (hex_base == 'h')
		ft_strlcpy(base, "0123456789abcdef", 17);

	else if (hex_base == 'H')
		ft_strlcpy(base, "0123456789ABCDEF", 17);

	if (number > 15)
	{
		ft_puthexa(number / 16, hex_base, len);
		ft_puthexa(number % 16, hex_base, len);
	}

	else
		ft_putchar_len(base[number], len);
}
