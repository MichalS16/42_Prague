/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 12:00:00 by msmiesko          #+#    #+#             */
/*   Updated: 2026/07/27 12:00:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str);
int	do_add(int a, int b);
int	do_sub(int a, int b);
int	do_mul(int a, int b);
int	do_div(int a, int b);
int	do_mod(int a, int b);

static void	run_op(int a, int b, char op)
{
	char			*ops;
	int				(*funcs[5])(int, int);
	int				i;

	ops = "+-/*%";
	funcs[0] = &do_add;
	funcs[1] = &do_sub;
	funcs[2] = &do_div;
	funcs[3] = &do_mul;
	funcs[4] = &do_mod;
	i = 0;
	while (ops[i])
	{
		if (op == ops[i])
		{
			funcs[i](a, b);
			write(1, "\n", 1);
			return ;
		}
		i++;
	}
	write(1, "0\n", 2);
}

int	main(int argc, char **argv)
{
	int	a;
	int	b;

	if (argc != 4)
		return (0);
	a = ft_atoi(argv[1]);
	b = ft_atoi(argv[3]);
	run_op(a, b, argv[2][0]);
	return (0);
}
