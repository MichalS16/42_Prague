/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:54:39 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/11 12:34:13 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

/*
#include <stdio.h>

int main(void)
{
	int a;
	int b;
	int div;
	int mod;

	a = 18;
	b = 7;
	ft_div_mod(a, b, &div, &mod);
	printf("a = %d, b= %d, div= %d, mod= %d\n", a,b, div, mod);
	return (0);
}
*/