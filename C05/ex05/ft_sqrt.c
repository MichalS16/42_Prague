/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:26:25 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/20 14:41:55 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb > 0)
	{
		while (i * i <= nb)
		{
			if (i * i == nb)
			{
				return (i);
			}
			if (i > 46340)
			{
				return (0);
			}
			i++;
		}
	}
	return (0);
}

/*
#include <stdio.h>
int main() {
	int	num1 = 16;
	int	num2 = 25;
	int	num3 = 9;
	int	num4 = 7;

	printf("Square root of %d is %d\n", num1, ft_sqrt(num1));
	printf("Square root of %d is %d\n", num2, ft_sqrt(num2));
	printf("Square root of %d is %d\n", num3, ft_sqrt(num3));
	printf("Square root of %d is %d\n", num4, ft_sqrt(num4));
	return (0);
}
*/