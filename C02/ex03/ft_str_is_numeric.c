/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:32:23 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/13 14:42:15 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_numeric(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		if ((str[index] < '0' || str[index] > '9'))
		{
			return (0);
		}
		index++;
	}
	return (1);
}

/*
#include <stdio.h>
int main()
{
	int		result;

	result = ft_str_is_numeric("123456789");
	printf("Result: %d\n", result);

	result = ft_str_is_numeric("asdIf1234");
	printf("Result: %d\n", result);

	result = ft_str_is_numeric("");
	printf("Result: %d\n", result);
	return 0;
}
*/