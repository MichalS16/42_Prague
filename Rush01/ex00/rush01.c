/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 10:00:00 by msmiesko          #+#    #+#             */
/*   Updated: 2026/07/27 10:00:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

static void	error(void)
{
	write(1, "Error\n", 6);
}

static int	count_visible(int *line, int size, int step, int start)
{
	int	max;
	int	seen;
	int	i;
	int	pos;

	max = 0;
	seen = 0;
	i = 0;
	pos = start;
	while (i < size)
	{
		if (line[pos] > max)
		{
			max = line[pos];
			seen++;
		}
		pos = pos + step;
		i++;
	}
	return (seen);
}

static int	row_ok(int grid[4][4], int r, int left, int right)
{
	int	line[4];
	int	c;

	c = 0;
	while (c < 4)
	{
		line[c] = grid[r][c];
		c++;
	}
	if (count_visible(line, 4, 1, 0) != left)
		return (0);
	if (count_visible(line, 4, -1, 3) != right)
		return (0);
	return (1);
}

static int	col_ok(int grid[4][4], int c, int top, int bottom)
{
	int	line[4];
	int	r;

	r = 0;
	while (r < 4)
	{
		line[r] = grid[r][c];
		r++;
	}
	if (count_visible(line, 4, 1, 0) != top)
		return (0);
	if (count_visible(line, 4, -1, 3) != bottom)
		return (0);
	return (1);
}

static int	value_used(int grid[4][4], int r, int c, int value)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i != c && grid[r][i] == value)
			return (1);
		if (i != r && grid[i][c] == value)
			return (1);
		i++;
	}
	return (0);
}

static int	solve(int grid[4][4], int pos, int *clues)
{
	int	r;
	int	c;
	int	v;

	if (pos == 16)
		return (1);
	r = pos / 4;
	c = pos % 4;
	v = 1;
	while (v <= 4)
	{
		if (!value_used(grid, r, c, v))
		{
			grid[r][c] = v;
			if (c != 3 || row_ok(grid, r, clues[8 + r], clues[12 + r]))
			{
				if (r != 3 || col_ok(grid, c, clues[c], clues[4 + c]))
				{
					if (solve(grid, pos + 1, clues))
						return (1);
				}
			}
			grid[r][c] = 0;
		}
		v++;
	}
	return (0);
}

static void	print_grid(int grid[4][4])
{
	int	r;
	int	c;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			ft_putchar('0' + grid[r][c]);
			c++;
		}
		ft_putchar('\n');
		r++;
	}
}

static int	parse_clues(char *str, int *clues)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			i++;
		}
		else if (str[i] >= '1' && str[i] <= '4' &&
			(str[i + 1] == ' ' || str[i + 1] == '\0'))
		{
			if (n >= 16)
				return (0);
			clues[n] = str[i] - '0';
			n++;
			i++;
		}
		else
			return (0);
	}
	return (n == 16);
}

static void	init_grid(int grid[4][4])
{
	int	r;
	int	c;

	r = 0;
	while (r < 4)
	{
		c = 0;
		while (c < 4)
		{
			grid[r][c] = 0;
			c++;
		}
		r++;
	}
}

void	rush(int argc, char **argv)
{
	int	clues[16];
	int	grid[4][4];

	if (argc != 2 || !parse_clues(argv[1], clues))
	{
		error();
		return ;
	}
	init_grid(grid);
	if (solve(grid, 0, clues))
		print_grid(grid);
	else
		error();
}
