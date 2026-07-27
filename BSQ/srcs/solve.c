/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by msmiesko          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	**alloc_dp(int rows, int cols)
{
	int	**dp;
	int	r;
	int	c;

	dp = (int **)malloc(sizeof(int *) * rows);
	if (!dp)
	{
		return (NULL);
	}
	r = 0;
	while (r < rows)
	{
		dp[r] = (int *)malloc(sizeof(int) * cols);
		if (!dp[r])
		{
			return (NULL);
		}
		c = 0;
		while (c < cols)
		{
			dp[r][c] = 0;
			c++;
		}
		r++;
	}
	return (dp);
}

static void	free_dp(int **dp, int rows)
{
	int	r;

	r = 0;
	while (r < rows)
	{
		free(dp[r]);
		r++;
	}
	free(dp);
}

static int	min3(int a, int b, int c)
{
	int	m;

	m = a;
	if (b < m)
	{
		m = b;
	}
	if (c < m)
	{
		m = c;
	}
	return (m);
}

static void	compute_dp(t_map *map, int **dp, int *best,
	int *best_r, int *best_c)
{
	int	r;
	int	c;

	r = 0;
	while (r < map->rows)
	{
		c = 0;
		while (c < map->cols)
		{
			if (map->grid[r][c] == map->empty)
			{
				if (r == 0 || c == 0)
				{
					dp[r][c] = 1;
				}
				else
				{
					dp[r][c] = 1 + min3(dp[r - 1][c], dp[r][c - 1],
							dp[r - 1][c - 1]);
				}
				if (dp[r][c] > *best)
				{
					*best = dp[r][c];
					*best_r = r - dp[r][c] + 1;
					*best_c = c - dp[r][c] + 1;
				}
			}
			c++;
		}
		r++;
	}
}

static void	fill_square(t_map *map, int size, int top, int left)
{
	int	r;
	int	c;

	r = top;
	while (r < top + size)
	{
		c = left;
		while (c < left + size)
		{
			map->grid[r][c] = map->full;
			c++;
		}
		r++;
	}
}

int	solve_map(t_map *map)
{
	int	**dp;
	int	best;
	int	best_r;
	int	best_c;

	dp = alloc_dp(map->rows, map->cols);
	if (!dp)
	{
		return (0);
	}
	best = 0;
	best_r = 0;
	best_c = 0;
	compute_dp(map, dp, &best, &best_r, &best_c);
	free_dp(dp, map->rows);
	if (best > 0)
	{
		fill_square(map, best, best_r, best_c);
	}
	return (1);
}
