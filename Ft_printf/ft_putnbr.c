/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:32:25 by msmiesko          #+#    #+#             */
/*   Updated: 2024/04/13 14:32:25 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *len)
{
	long int	n_long;

	n_long = n;
	if (n_long < 0)
	{
		n_long = -n_long;
		ft_putchar_len('-', len);
	}
	if (n_long > 9)
	{
		ft_putnbr(n_long / 10, len);
		ft_putnbr(n_long % 10, len);
	}
	else
		ft_putchar_len(n_long + '0', len);
}
