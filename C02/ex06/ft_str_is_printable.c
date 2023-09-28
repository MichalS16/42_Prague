/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:32:23 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/15 11:08:13 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		if ((str[index] < 32 || str[index] > 126))
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

	result = ft_str_is_printable("asIEdf");
	printf("Result: %d\n", result);

	result = ft_str_is_printable("asd f12");
	printf("Result: %d\n", result);

	result = ft_str_is_printable("AB?JX€NCJSNCJN");
	printf("Result: %d\n", result);

	result = ft_str_is_printable("");
	printf("Result: %d\n", result);
	return 0;
}
*/
