/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by msmiesko          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static int	is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

static int	parse_header(const char *line, t_map *map)
{
	int	i;
	int	len;
	int	n;

	len = str_len(line);
	if (len < 4)
	{
		return (0);
	}
	i = 0;
	n = 0;
	while (is_digit(line[i]))
	{
		n = n * 10 + (line[i] - '0');
		i++;
	}
	if (i == 0 || i != len - 3)
	{
		return (0);
	}
	if (n <= 0)
	{
		return (0);
	}
	if (!is_printable(line[i]) || !is_printable(line[i + 1])
		|| !is_printable(line[i + 2]))
	{
		return (0);
	}
	if (line[i] == line[i + 1] || line[i] == line[i + 2]
		|| line[i + 1] == line[i + 2])
	{
		return (0);
	}
	map->rows = n;
	map->empty = line[i];
	map->obstacle = line[i + 1];
	map->full = line[i + 2];
	return (1);
}

static int	check_row(t_map *map, const char *row)
{
	int	c;

	if (!row || str_len(row) != map->cols)
	{
		return (0);
	}
	c = 0;
	while (c < map->cols)
	{
		if (row[c] != map->empty && row[c] != map->obstacle)
		{
			return (0);
		}
		c++;
	}
	return (1);
}

static int	fill_grid(char **lines, t_map *map)
{
	int	r;

	map->grid = (char **)malloc(sizeof(char *) * map->rows);
	if (!map->grid)
	{
		return (0);
	}
	r = 0;
	while (r < map->rows)
	{
		if (!check_row(map, lines[r + 1]))
		{
			return (0);
		}
		map->grid[r] = lines[r + 1];
		r++;
	}
	return (1);
}

int	parse_map(const char *content, t_map *map)
{
	char	**lines;
	int		n_lines;
	int		ok;

	map->grid = NULL;
	if (!content || str_len(content) == 0)
	{
		return (0);
	}
	n_lines = split_lines_count(content);
	if (n_lines < 2)
	{
		return (0);
	}
	lines = split_lines(content, n_lines);
	if (!lines)
	{
		return (0);
	}
	ok = parse_header(lines[0], map);
	if (!ok || n_lines - 1 != map->rows)
	{
		free_split(lines);
		return (0);
	}
	map->cols = str_len(lines[1]);
	if (map->cols <= 0)
	{
		free_split(lines);
		return (0);
	}
	ok = fill_grid(lines, map);
	if (!ok)
	{
		free(map->grid);
		map->grid = NULL;
		free_split(lines);
		return (0);
	}
	free(lines[0]);
	free(lines);
	return (1);
}
