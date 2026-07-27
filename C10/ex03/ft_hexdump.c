/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by msmiesko          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "ft_hexdump.h"

static void	ft_print_line(unsigned char *buf, int len, long off)
{
	ft_print_offset(off);
	ft_putstr("  ");
	ft_print_hex_row(buf, len);
	ft_putstr(" ");
	ft_print_ascii(buf, len);
}

static int	ft_dump(int fd)
{
	unsigned char	buf[16];
	int				len;
	long			off;

	off = 0;
	len = read(fd, buf, 16);
	while (len > 0)
	{
		ft_print_line(buf, len, off);
		off += len;
		len = read(fd, buf, 16);
	}
	if (len < 0)
		return (1);
	ft_print_offset(off);
	ft_putstr("\n");
	return (0);
}

static int	open_target(int argc, char **argv, int file_idx)
{
	int	fd;

	if (file_idx >= argc)
		return (0);
	fd = open(argv[file_idx], O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("ft_hexdump: ", 2);
		ft_putstr_fd(argv[file_idx], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
	}
	return (fd);
}

int	main(int argc, char **argv)
{
	int	fd;
	int	file_idx;
	int	ret;

	file_idx = 1;
	if (argc > 1 && ft_starts_with(argv[1], "-C"))
		file_idx = 2;
	fd = open_target(argc, argv, file_idx);
	if (fd < 0)
		return (1);
	ret = ft_dump(fd);
	if (fd != 0)
		close(fd);
	return (ret);
}
