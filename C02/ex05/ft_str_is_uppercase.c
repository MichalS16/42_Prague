/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:32:23 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/13 14:42:43 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_uppercase(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		if ((str[index] < 'A' || str[index] > 'Z'))
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

	result = ft_str_is_uppercase("asIEdf");
	printf("Result: %d\n", result);

	result = ft_str_is_uppercase("asdf12");
	printf("Result: %d\n", result);

	result = ft_str_is_uppercase("ABJXNCJSNCJN");
	printf("Result: %d\n", result);

	result = ft_str_is_uppercase("");
	printf("Result: %d\n", result);
	return 0;
}
*/