/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:32:23 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/13 14:43:22 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if ((str[index] >= 'A' && str[index] <= 'Z'))
		{
			str[index] += 32;
		}
		index++;
	}
	return (str);
}

/*
#include <stdio.h>
int main()
{
	char result1[] = "asIEdf";
	char result2[] = "ASDASDDAS124?";
	char result3[] = "kasndjkndlaskdn";
	char result4[] = "";

	printf("Result: %s\n", ft_strlowcase(result1));
	printf("Result: %s\n", ft_strlowcase(result2));
	printf("Result: %s\n", ft_strlowcase(result3));
	printf("Result: %s\n", ft_strlowcase(result4));
	return 0;
}
*/