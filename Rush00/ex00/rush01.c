/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 14:24:19 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/24 11:08:37 by msmiesko         ###   ########.fr       */
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
			if ((r == 1 && c == 1) || (c == x && r == y && x > 1 && y > 1))
				ft_putchar('/');
			else if ((r == 1 && c == x) || (r == y && c == 1))
				ft_putchar('\\');
			else if (r == 1 || r == y || c == 1 || c == x)
				ft_putchar('*');
			else
				ft_putchar(' ');
			c++;
		}
		ft_putchar('\n');
		r++;
	}
}

void	error(char	*massage)
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
