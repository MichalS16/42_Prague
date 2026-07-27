/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:23:28 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/20 14:24:33 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = nb;
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	while (power > 1)
	{
		result *= nb;
		power--;
	}
	return (result);
}

/*
#include <stdio.h>
int main()
{
	printf("%d^%d = %d\n", 2, 3, ft_iterative_power(2, 3));
	return (0);
}
*/