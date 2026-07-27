/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by msmiesko          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str);
int	member(char c, char *base);
int	to_decimal(char c, char *base);
int	base_is_valid(char *base);

static int	parse_nbr(char *nbr, char *base_from, int *sign)
{
	int	i;
	int	number;

	i = 0;
	*sign = 1;
	while (nbr[i] == ' ' || (nbr[i] >= 9 && nbr[i] <= 13))
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			*sign *= -1;
		i++;
	}
	number = 0;
	while (nbr[i] && member(nbr[i], base_from))
	{
		number = number * ft_strlen(base_from) + to_decimal(nbr[i], base_from);
		i++;
	}
	return (number);
}

static int	count_digits(int nbr, int base_len)
{
	int	count;

	count = 1;
	if (nbr < 0)
		nbr *= -1;
	while (nbr >= base_len)
	{
		nbr = nbr / base_len;
		count++;
	}
	return (count);
}

static void	fill_digits(char *str, int nbr, char *base_to, int start)
{
	int	base_len;
	int	i;

	base_len = ft_strlen(base_to);
	if (nbr < 0)
		nbr *= -1;
	i = start;
	if (nbr == 0)
	{
		str[i] = base_to[0];
		return ;
	}
	while (nbr > 0)
	{
		str[i] = base_to[nbr % base_len];
		nbr = nbr / base_len;
		i--;
	}
}

static char	*alloc_result(int dec, int sign, char *base_to, int *out_len)
{
	int		digits;
	int		len;
	char	*str;

	digits = count_digits(dec, ft_strlen(base_to));
	len = digits;
	if (sign < 0 && dec != 0)
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (str)
	{
		str[len] = '\0';
		if (sign < 0 && dec != 0)
			str[0] = '-';
	}
	*out_len = len;
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		sign;
	int		dec;
	int		len;
	char	*str;

	if (!base_is_valid(base_from) || !base_is_valid(base_to))
		return (0);
	dec = parse_nbr(nbr, base_from, &sign);
	str = alloc_result(dec, sign, base_to, &len);
	if (!str)
		return (0);
	fill_digits(str, dec, base_to, len - 1);
	return (str);
}
