/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by msmiesko          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	str_len(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	split_lines_count(const char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			count++;
		}
		i++;
	}
	if (i > 0 && s[i - 1] != '\n')
	{
		count++;
	}
	return (count);
}

static char	*dup_line(const char *s, int start, int end)
{
	char	*line;
	int		i;

	line = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!line)
	{
		return (NULL);
	}
	i = 0;
	while (start + i < end)
	{
		line[i] = s[start + i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	**split_lines(const char *s, int n_expected)
{
	char	**lines;
	int		i;
	int		start;
	int		idx;

	lines = (char **)malloc(sizeof(char *) * (n_expected + 1));
	if (!lines)
	{
		return (NULL);
	}
	i = 0;
	start = 0;
	idx = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			if (idx < n_expected)
			{
				lines[idx] = dup_line(s, start, i);
				idx++;
			}
			start = i + 1;
		}
		i++;
	}
	if (start < i && idx < n_expected)
	{
		lines[idx] = dup_line(s, start, i);
		idx++;
	}
	while (idx <= n_expected)
	{
		lines[idx] = NULL;
		idx++;
	}
	return (lines);
}

void	free_split(char **lines)
{
	int	i;

	if (!lines)
	{
		return ;
	}
	i = 0;
	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}
