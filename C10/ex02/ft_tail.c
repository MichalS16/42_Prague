/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by msmiesko          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include "ft_tail.h"

#define BUF_SIZE 4096

static void	ft_tail_print(char *buf, long start, long end)
{
	if (end > start)
		write(1, buf + start, end - start);
}

static char	*read_whole_file(int fd, long *out_size)
{
	char	*buf;
	long	cap;
	long	size;
	int		ret;

	cap = BUF_SIZE;
	buf = malloc(cap);
	if (!buf)
		return (NULL);
	size = 0;
	ret = read(fd, buf, cap);
	while (ret > 0)
	{
		size += ret;
		if (size == cap)
		{
			cap *= 2;
			buf = realloc(buf, cap);
			if (!buf)
				return (NULL);
		}
		ret = read(fd, buf + size, cap - size);
	}
	*out_size = size;
	return (buf);
}

static void	ft_tail_file(char *name, long n)
{
	int		fd;
	char	*buf;
	long	size;

	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		ft_error(name, strerror(errno));
		return ;
	}
	buf = read_whole_file(fd, &size);
	if (!buf)
	{
		close(fd);
		return ;
	}
	if (n < size)
		ft_tail_print(buf, size - n, size);
	else
		ft_tail_print(buf, 0, size);
	free(buf);
	close(fd);
}

int	main(int argc, char **argv)
{
	long	n;
	int		file_idx;

	n = 10;
	file_idx = 1;
	if (argc > 1 && ft_str_eq(argv[1], "-c"))
	{
		if (argc < 4)
		{
			ft_error("tail", "option requires an argument -- 'c'");
			return (1);
		}
		n = ft_atol(argv[2]);
		file_idx = 3;
	}
	if (file_idx >= argc)
	{
		ft_error("tail", "missing file operand");
		return (1);
	}
	ft_tail_file(argv[file_idx], n);
	return (0);
}
