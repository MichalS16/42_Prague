/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:54:04 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/20 14:23:10 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	result = 1;
	if (nb < 0)
	{
		return (0);
	}
	if (nb == 0 || nb == 1)
	{
		return (1);
	}
	while (nb > 0)
	{
		result *= nb;
		nb--;
	}
	return (result);
}

/*
#include <stdio.h>
int	main()
{
	int number = 2;

	printf("The factorial of %d is: %d", number, ft_iterative_factorial(number));
	return (0);
}
*/