/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 11:03:26 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/22 11:58:50 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	to_hexadecimal(unsigned char c)
{
	char	*hexadecimals;

	hexadecimals = "0123456789abcdef";
	if (c / 16 > 0)
	{
		ft_putchar(hexadecimals[c / 16]);
		ft_putchar(hexadecimals[c % 16]);
	}
	else
	{
		ft_putchar('0');
		ft_putchar(hexadecimals[c]);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if ((str[index] <= 31 || str[index] >= 126))
		{
			ft_putchar('\\');
			to_hexadecimal(str[index]);
		}
		else
		{
			ft_putchar(str[index]);
		}
		index++;
	}
}

/*
int	main()
{
	char str[] = "Hello, \nWorld!\tNon-printable: \x02\x1F";
	ft_putstr_non_printable(str);
	return 0;
}
*/