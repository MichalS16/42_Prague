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

#include "rush02.h"
#include <unistd.h>

static char	*get_number_arg(int argc, char **argv, char **dict_path)
{
	if (argc == 2)
	{
		*dict_path = REF_DICT;
		return (argv[1]);
	}
	*dict_path = argv[1];
	return (argv[2]);
}

static void	run(char *dict_path, char *number)
{
	t_entry	*dict;
	int		fail;
	char	*result;

	if (!is_valid_number(number))
	{
		ft_error("Error\n");
		return ;
	}
	dict = load_dict(dict_path, &fail);
	if (fail)
	{
		ft_error("Dict Error\n");
		return ;
	}
	fail = 0;
	result = convert_number(number, dict, &fail);
	if (fail || !result)
	{
		ft_error("Dict Error\n");
		if (result)
			free(result);
		free_dict(dict);
		return ;
	}
	write(1, result, ft_strlen(result));
	write(1, "\n", 1);
	free(result);
	free_dict(dict);
}

int	main(int argc, char **argv)
{
	char	*dict_path;
	char	*number;

	if (argc != 2 && argc != 3)
	{
		ft_error("Error\n");
		return (0);
	}
	number = get_number_arg(argc, argv, &dict_path);
	run(dict_path, number);
	return (0);
}
