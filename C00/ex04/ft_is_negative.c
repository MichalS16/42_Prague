/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:36:56 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/12 10:04:27 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	sign;

	if (n < 0)
	{
		sign = 'N';
	}
	else
	{
		sign = 'P';
	}
	write(1, &sign, 1);
}

/*
int main(void)
{
	int n;
	
	n = 0;
	ft_is_negative(n);
	return 0;
}
*/