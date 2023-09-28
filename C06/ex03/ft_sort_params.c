/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:01:58 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/21 13:04:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	sort(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] == str2[i] && str1[i])
	{
		i++;
	}
	return (str2[i] - str1[i]);
}

void	print_result(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write (1, "\n", 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*temp;
	int		repete;
	int		index;

	repete = 0;
	while (repete < argc)
	{
		index = 1;
		while (index < argc - 1)
		{
			if (sort(argv[index], argv[index + 1]) < 0)
			{
				temp = argv[index];
				argv[index] = argv[index + 1];
				argv[index + 1] = temp;
			}
			index++;
		}
		repete++;
	}
	print_result(argc, argv);
	return (0);
}
