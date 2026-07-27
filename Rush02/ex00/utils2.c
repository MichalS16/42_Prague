/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by msmiesko          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}

static char	*grow_buffer(char *buf, size_t old_len, char *chunk, int read_len)
{
	char	*new_buf;
	size_t	i;

	new_buf = (char *)malloc(old_len + (size_t)read_len + 1);
	if (!new_buf)
		return (NULL);
	i = 0;
	while (i < old_len)
	{
		new_buf[i] = buf[i];
		i++;
	}
	i = 0;
	while (i < (size_t)read_len)
	{
		new_buf[old_len + i] = chunk[i];
		i++;
	}
	new_buf[old_len + i] = '\0';
	if (buf)
		free(buf);
	return (new_buf);
}

char	*read_all(int fd)
{
	char	chunk[4097];
	char	*buf;
	int		r;
	size_t	len;

	buf = NULL;
	len = 0;
	r = read(fd, chunk, 4096);
	while (r > 0)
	{
		chunk[r] = '\0';
		buf = grow_buffer(buf, len, chunk, r);
		if (!buf)
			return (NULL);
		len += (size_t)r;
		r = read(fd, chunk, 4096);
	}
	if (!buf)
	{
		buf = (char *)malloc(1);
		if (buf)
			buf[0] = '\0';
	}
	return (buf);
}

static int	count_lines(char *content)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (content[0] != '\0')
		count = 1;
	while (content[i] != '\0')
	{
		if (content[i] == '\n' && content[i + 1] != '\0')
			count++;
		i++;
	}
	return (count);
}

char	**split_lines(char *content, int *count)
{
	char	**lines;
	int		i;
	int		start;
	int		idx;

	*count = count_lines(content);
	lines = (char **)malloc(sizeof(char *) * (size_t)(*count + 1));
	if (!lines)
		return (NULL);
	i = 0;
	start = 0;
	idx = 0;
	while (content[i] != '\0')
	{
		if (content[i] == '\n')
		{
			lines[idx] = (char *)malloc((size_t)(i - start + 1));
			{
				int	j;

				j = 0;
				while (start + j < i)
				{
					lines[idx][j] = content[start + j];
					j++;
				}
				lines[idx][j] = '\0';
			}
			idx++;
			start = i + 1;
		}
		i++;
	}
	if (start < i)
	{
		lines[idx] = (char *)malloc((size_t)(i - start + 1));
		{
			int	j;

			j = 0;
			while (start + j < i)
			{
				lines[idx][j] = content[start + j];
				j++;
			}
			lines[idx][j] = '\0';
		}
		idx++;
	}
	lines[idx] = NULL;
	return (lines);
}

void	free_lines(char **lines)
{
	int	i;

	if (!lines)
		return ;
	i = 0;
	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}
