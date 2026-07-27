/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by msmiesko          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	print_map(t_map *map)
{
	int	r;

	r = 0;
	while (r < map->rows)
	{
		write(1, map->grid[r], map->cols);
		write(1, "\n", 1);
		r++;
	}
}

void	free_map(t_map *map)
{
	int	r;

	if (!map->grid)
	{
		return ;
	}
	r = 0;
	while (r < map->rows)
	{
		free(map->grid[r]);
		r++;
	}
	free(map->grid);
	map->grid = NULL;
}
