/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 12:13:15 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/24 16:13:09 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_check_lenght(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || base[i] < 32 || base[i] > 126)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		i++;
	}
	if (i <= 1)
	{
		return (0);
	}
	return (i);
}

int	member(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	to_decimal(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
		{
			return (i);
		}
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	number;
	int	i;

	sign = 1;
	i = 0;
	number = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
	{
		i++;
	}
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (base_check_lenght(base) != 0 && str[i] && member(str[i], base))
	{
		number = number * base_check_lenght(base) + to_decimal(str[i], base);
		i++;
	}
	return (number * sign);
}

/*
#include <stdio.h>
int main() {
	char	*base = "0123456789ABCDEF";
	char	*base1 = "01";
	char	*str1 = "1A";
	char	*str2 = "15";
	char	*str3 = "ZZ";
	char	*str4 = "100010111010";

	printf("Result 1: %d\n", ft_atoi_base(str1, base));
	printf("Result 2: %d\n", ft_atoi_base(str2, base));
	printf("Result 3: %d\n", ft_atoi_base(str3, base));
	printf("Result 4: %d\n", ft_atoi_base(str4, base1));
	return (0);
}
*/