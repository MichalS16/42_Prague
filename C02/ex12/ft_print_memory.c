/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 22:42:57 by marvin            #+#    #+#             */
/*   Updated: 2023/09/24 22:42:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_hexadecimal(unsigned long long nb, int prev, char c, int i)
{
	char	*base;

	base = "0123456789abcdef";
	if (i == 1)
	{
		write(1, &base[c / 16], 1);
		write(1, &base[c % 16], 1);
	}
	else
	{
		if (nb < 16 && prev == 1)
			write(1, "0", 1);
		if (nb >= 16)
		{
			print_hexadecimal(nb / 16, 0, 'a', 0);
			print_hexadecimal(nb % 16, 0, 'a', 0);
		}
		else
		{
			write(1, &base[nb], 1);
		}
	}
}

void	first_hexa_adress(unsigned long long addr)
{
	unsigned long long	tmp;
	int					i;

	tmp = addr;
	i = 1;
	while (i++ < 15)
	{
		if (tmp < 16)
			write(1, "0", 1);
		tmp /= 16;
	}
	print_hexadecimal(addr, 0, 'a', 0);
}

void	ft_print_line(char *addr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		print_hexadecimal(0, 0, addr[i], 1);
		if ((i - 1) % 2 == 0)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, "     ", 5);
		i += 2;
	}
	i = 0;
	while (i < size)
	{
		if (addr[i] >= 32 && addr[i] <= 126)
			write(1, &addr[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	numbr_char;
	unsigned int	i;

	i = 0;
	while (size > 0)
	{
		if (size >= 16)
		{
			numbr_char = 16;
			size -= 16;
		}
		else
		{
			numbr_char = size;
			size = 0;
		}
		first_hexa_adress((unsigned long long)addr + 16 * i);
		write(1, ": ", 2);
		ft_print_line(addr + 16 * i, numbr_char);
		write(1, "\n", 1);
		i++;
	}
	return (addr);
}

/*
#include <stdio.h>
int main()
{
	char text[] = "Bonjour les aminches\t\n\tc\a est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol\tlol\n ";
	ft_print_memory(text, sizeof(text));
	return (0);
}
*/