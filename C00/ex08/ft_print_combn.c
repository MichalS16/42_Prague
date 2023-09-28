/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:32:57 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/22 10:54:45 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnumber(int n, int *number)
{
	int	index;

	index = 0;
	while (index < n)
	{
		ft_putchar(number[index] + '0');
		index++;
	}
}

void	ft_print_another_comb(int n, int *number)
{
	int	index;
	int	max;

	index = n - 1;
	max = 9;
	while (number[index] == max)
	{
		index -= 1;
		max -= 1;
	}
	number[index] += 1;
	while (index < n)
	{
		number[index + 1] = number[index] + 1;
		index += 1;
	}
}

void	ft_print_combn(int n)
{
	int	index;
	int	number[10];

	index = 0;
	while (index < n)
	{
		number[index] = index;
		index++;
	}
	ft_putnumber(n, number);
	while (number[0] != 10 - n)
	{
		ft_putchar(',');
		ft_putchar(' ');
		ft_print_another_comb(n, number);
		ft_putnumber(n, number);
	}
}

/*
int	main(void)
{
	ft_print_combn(9);
	return (0);
}
*/