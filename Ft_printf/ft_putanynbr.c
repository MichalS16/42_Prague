/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putanynbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:01:07 by msmiesko          #+#    #+#             */
/*   Updated: 2024/04/13 16:01:07 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putanynbr(unsigned int n, int *len)
{
	unsigned long int	n_long;

	n_long = n;
	if (n_long > 9)
	{
		ft_putanynbr(n_long / 10, len);
		ft_putanynbr(n_long % 10, len);
	}
	else
		ft_putchar_c(n_long + '0', len);
}