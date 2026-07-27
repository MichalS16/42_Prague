/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:32:23 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/13 14:42:29 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_lowercase(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		if ((str[index] < 'a' || str[index] > 'z'))
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

	result = ft_str_is_lowercase("asIEdf");
	printf("Result: %d\n", result);

	result = ft_str_is_lowercase("asdf12");
	printf("Result: %d\n", result);

	result = ft_str_is_lowercase("abchdwjdjsd");
	printf("Result: %d\n", result);

	result = ft_str_is_lowercase("");
	printf("Result: %d\n", result);
	return 0;
}
*/