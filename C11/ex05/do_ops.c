/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 12:00:00 by msmiesko          #+#    #+#             */
/*   Updated: 2026/07/27 12:00:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb);

int	do_add(int a, int b)
{
	ft_putnbr(a + b);
	return (0);
}

int	do_sub(int a, int b)
{
	ft_putnbr(a - b);
	return (0);
}

int	do_mul(int a, int b)
{
	ft_putnbr(a * b);
	return (0);
}

int	do_div(int a, int b)
{
	if (b == 0)
	{
		write(1, "Stop : division by zero\n", 25);
		return (0);
	}
	ft_putnbr(a / b);
	return (0);
}

int	do_mod(int a, int b)
{
	if (b == 0)
	{
		write(1, "Stop : modulo by zero\n", 22);
		return (0);
	}
	ft_putnbr(a % b);
	return (0);
}
