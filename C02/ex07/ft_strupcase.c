/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:32:23 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/13 14:43:09 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strupcase(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if ((str[index] >= 'a' && str[index] <= 'z'))
		{
			str[index] -= 32;
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

	printf("Result: %s\n", ft_strupcase(result1));
	printf("Result: %s\n", ft_strupcase(result2));
	printf("Result: %s\n", ft_strupcase(result3));
	printf("Result: %s\n", ft_strupcase(result4));
	return 0;
}
*/