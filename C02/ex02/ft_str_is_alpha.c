/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 14:05:24 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/13 14:41:58 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		if ((str[index] < 'a' || str[index] > 'z'))
		{
			if (str[index] < 'A' || str[index] > 'Z')
			{
				return (0);
			}
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

	result = ft_str_is_alpha("asIEdf");
	printf("Result: %d\n", result);

	result = ft_str_is_alpha("asdf1234");
	printf("Result: %d\n", result);

	result = ft_str_is_alpha("");
	printf("Result: %d\n", result);
	return 0;
}
*/