/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by msmiesko          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
	char	**grid;
}	t_map;

typedef struct s_file
{
	char	*data;
	int		len;
}	t_file;

/* read_utils.c */
char	*read_file(const char *path, int *ok);
char	*read_stdin(int *ok);

/* parse.c */
int		parse_map(const char *content, t_map *map);

/* solve.c */
int		solve_map(t_map *map);

/* print.c */
void	print_map(t_map *map);
void	free_map(t_map *map);

/* str_utils.c */
int		str_len(const char *s);
int		split_lines_count(const char *s);
char	**split_lines(const char *s, int n_expected);
void	free_split(char **lines);
int		is_digit(char c);

#endif
