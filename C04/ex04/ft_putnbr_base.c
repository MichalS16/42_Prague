/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 09:42:53 by marvin            #+#    #+#             */
/*   Updated: 2023/09/24 09:42:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void	print_base(int nbr, char *base, int size)
{
	unsigned int	number;

	if (nbr < 0)
	{
		write(1, "-", 1);
		number = -nbr;
	}
	else
		number = nbr;
	if (number >= (unsigned int)size)
	{
		print_base(number / size, base, size);
	}
	write(1, &base[number % size], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	if (base_check_lenght(base) > 1)
	{
		print_base(nbr, base, base_check_lenght(base));
	}
}

/*
int main()
{
	char	*base1 = "0123456789ABCDEF";
	char	*base2 = "01";
	int	number = 42;

	ft_putnbr_base(number, base1);
	write(1, "\n", 1);
	ft_putnbr_base(number, base2);
	return (0);
}
*/