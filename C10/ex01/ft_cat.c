/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
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
#include <string.h>

#define BUF_SIZE 30000

static void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	write(fd, s, i);
}

static void	ft_print_one(char *name)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE];

	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("ft_cat: ", 2);
		ft_putstr_fd(name, 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return ;
	}
	ret = read(fd, buf, BUF_SIZE);
	while (ret > 0)
	{
		write(1, buf, ret);
		ret = read(fd, buf, BUF_SIZE);
	}
	close(fd);
}

int	main(int argc, char **argv)
{
	int		i;
	int		ret;
	char	buf[BUF_SIZE];

	i = 1;
	if (argc == 1)
	{
		ret = read(0, buf, BUF_SIZE);
		while (ret > 0)
		{
			write(1, buf, ret);
			ret = read(0, buf, BUF_SIZE);
		}
		return (0);
	}
	while (i < argc)
	{
		ft_print_one(argv[i]);
		i++;
	}
	return (0);
}
