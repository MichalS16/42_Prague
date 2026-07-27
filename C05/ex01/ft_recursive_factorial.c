/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 12:14:55 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/20 12:46:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
	{
		return (0);
	}
	else if (nb <= 1)
	{
		return (1);
	}
	else
	{
		return (nb * ft_recursive_factorial (nb -1));
	}
}

/*
#include <stdio.h>
int	main()
{
	int number = 3;

	printf("The factorial of %d is: %d", number, ft_recursive_factorial(number));
	return (0);
}
*/