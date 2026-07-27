/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by msmiesko          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	ft_print_hex_byte(unsigned char c)
{
	char	*hex;
	char	out[3];

	hex = "0123456789abcdef";
	out[0] = hex[c / 16];
	out[1] = hex[c % 16];
	out[2] = '\0';
	ft_putstr(out);
}

void	ft_print_offset(long off)
{
	int		i;
	char	out[9];

	i = 7;
	out[8] = '\0';
	while (i >= 0)
	{
		out[i] = "0123456789abcdef"[off % 16];
		off = off / 16;
		i--;
	}
	ft_putstr(out);
}

void	ft_print_ascii(unsigned char *buf, int len)
{
	int		i;
	char	c[2];

	i = 0;
	ft_putstr("|");
	c[1] = '\0';
	while (i < len)
	{
		if (buf[i] >= 32 && buf[i] < 127)
			c[0] = buf[i];
		else
			c[0] = '.';
		ft_putstr(c);
		i++;
	}
	ft_putstr("|\n");
}

void	ft_print_hex_row(unsigned char *buf, int len)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (i < len)
			ft_print_hex_byte(buf[i]);
		else
			ft_putstr("  ");
		ft_putstr(" ");
		if (i == 7)
			ft_putstr(" ");
		i++;
	}
}
