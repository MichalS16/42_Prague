/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:32:12 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/12 10:32:01 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbrwithzero(int nb)
{
	int		f;

	f = '0';
	if (nb <= 9)
	{
		write(1, &f, 1);
		f = nb + '0';
		write(1, &f, 1);
	}
	else
	{
		f = (nb / 10) + '0';
		write(1, &f, 1);
		f = (nb % 10) + '0';
		write(1, &f, 1);
	}
}

void	ft_print_comb2(void)
{
	int	f;
	int	s;

	f = 0;
	while (f <= 99)
	{
		s = f + 1;
		while (s <= 99)
		{
			ft_putnbrwithzero(f);
			ft_putchar(' ');
			ft_putnbrwithzero(s);
			if (f < 98)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
			s++;
		}
		f++;
	}
}

/*
int	main(void)
{
	ft_print_comb2();
	return (0);
}
*/