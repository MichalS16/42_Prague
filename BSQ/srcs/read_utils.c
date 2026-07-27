/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by msmiesko          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <fcntl.h>

# define BUF_SIZE 4096

static char	*grow_buffer(char *buf, int cap, int *new_cap)
{
	char	*new_buf;
	int		i;

	*new_cap = cap * 2;
	new_buf = (char *)malloc(sizeof(char) * (*new_cap));
	if (!new_buf)
	{
		free(buf);
		return (NULL);
	}
	i = 0;
	while (i < cap)
	{
		new_buf[i] = buf[i];
		i++;
	}
	free(buf);
	return (new_buf);
}

static char	*append_chunk(char *buf, int *cap, int *len, char *tmp, int n)
{
	int	i;

	while (*len + n >= *cap)
	{
		buf = grow_buffer(buf, *cap, cap);
		if (!buf)
		{
			return (NULL);
		}
	}
	i = 0;
	while (i < n)
	{
		buf[*len] = tmp[i];
		(*len)++;
		i++;
	}
	return (buf);
}

static char	*read_fd(int fd, int *ok)
{
	char	*buf;
	char	tmp[BUF_SIZE];
	int		cap;
	int		len;
	long	r;

	cap = BUF_SIZE;
	len = 0;
	buf = (char *)malloc(sizeof(char) * cap);
	if (!buf)
	{
		*ok = 0;
		return (NULL);
	}
	r = read(fd, tmp, BUF_SIZE);
	while (r > 0)
	{
		buf = append_chunk(buf, &cap, &len, tmp, (int)r);
		if (!buf)
		{
			*ok = 0;
			return (NULL);
		}
		r = read(fd, tmp, BUF_SIZE);
	}
	if (r < 0)
	{
		free(buf);
		*ok = 0;
		return (NULL);
	}
	buf[len] = '\0';
	*ok = 1;
	return (buf);
}

char	*read_file(const char *path, int *ok)
{
	int		fd;
	char	*content;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		*ok = 0;
		return (NULL);
	}
	content = read_fd(fd, ok);
	close(fd);
	return (content);
}

char	*read_stdin(int *ok)
{
	return (read_fd(0, ok));
}
