/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by msmiesko          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

static void	process_one(const char *content, int read_ok)
{
	t_map	map;

	if (!read_ok || !parse_map(content, &map))
	{
		write(1, "map error\n", 10);
		return ;
	}
	if (!solve_map(&map))
	{
		write(1, "map error\n", 10);
		free_map(&map);
		return ;
	}
	print_map(&map);
	free_map(&map);
}

static void	process_file(const char *path)
{
	char	*content;
	int		ok;

	content = read_file(path, &ok);
	process_one(content, ok);
	if (content)
	{
		free(content);
	}
}

static void	process_stdin(void)
{
	char	*content;
	int		ok;

	content = read_stdin(&ok);
	process_one(content, ok);
	if (content)
	{
		free(content);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		process_stdin();
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		process_file(argv[i]);
		if (i + 1 < argc)
		{
			write(1, "\n", 1);
		}
		i++;
	}
	return (0);
}
