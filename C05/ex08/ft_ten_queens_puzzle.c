/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:46:25 by marvin            #+#    #+#             */
/*   Updated: 2023/09/24 22:46:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_out(int table[10])
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = table[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	checking(int table[10], int x, int y)
{
	int	j;

	j = 0;
	while (j < x)
	{
		if (y == table[j] || j + table[j] == x + y || j - table[j] == x - y)
		{
			return (0);
		}
		j++;
	}
	return (1);
}

void	queens_recursion(int table[10], int *res, int pos)
{
	int		i;

	if (pos == 10)
	{
		*res += 1;
		print_out(table);
	}
	else
	{
		i = 0;
		while (i < 10)
		{
			if (checking(table, pos, i))
			{
				table[pos] = i;
				queens_recursion(table, res, pos + 1);
			}
			i++;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	table[10];
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (i < 10)
	{
		table[i] = -1;
		i++;
	}
	queens_recursion(table, &result, 0);
	return (result);
}

/*
#include <stdio.h>
int	main(void)
{
	printf("Result: %d\n", ft_ten_queens_puzzle());
}
*/