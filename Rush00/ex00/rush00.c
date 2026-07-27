/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:54:52 by kmalenin          #+#    #+#             */
/*   Updated: 2023/09/24 11:08:31 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rectangle(int x, int y)
{
	int	r;
	int	c;

	r = 1;
	while (r <= y)
	{
		c = 1;
		while (c <= x)
		{
			if ((r == 1 || r == y) && c != 1 && c != x)
				ft_putchar('-');
			else if ((c == 1 || c == x) && r != 1 && r != y)
				ft_putchar('|');
			else if (r == 1 || c == 1 || r == y || c == x)
				ft_putchar('o');
			else
				ft_putchar(' ');
			c++;
		}
		ft_putchar('\n');
		r++;
	}
}

void	error(char *massage)
{
	int	i;

	i = 0;
	while (massage[i] != '\0')
	{
		write(1, &massage[i], 1);
		i++;
	}
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0)
	{
		error("Error, enter positive numbers, please!\n");
	}
	else
	{
		rectangle(x, y);
	}
}
