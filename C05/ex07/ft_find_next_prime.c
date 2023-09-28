/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:03:42 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/20 17:12:46 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 5;
	if (nb == 2 || nb == 3)
	{
		return (1);
	}
	if (nb <= 1 || nb % 2 == 0 || nb % 3 == 0)
	{
		return (0);
	}
	while (i <= nb / i)
	{
		if (nb % i == 0 || nb % (i + 2) == 0)
		{
			return (0);
		}
		i += 6;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
	{
		return (2);
	}
	while (!ft_is_prime(nb))
	{
		nb++;
	}
	return (nb);
}

/*
#include <stdio.h>
int	main()
{
	int number;

	number = 52;
	printf("number: %d, next prime: %d.\n", number, ft_find_next_prime(number));

	return 0;
}
*/