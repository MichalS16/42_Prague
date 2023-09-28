/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:32:23 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/17 12:38:56 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if ((str[index] >= 'A' && str[index] <= 'Z'))
		{
			str[index] += 32;
		}
		if (str[index] >= 'a' && str[index] <= 'z')
		{
			if (!(str[index -1] >= 'a' && str[index -1] <= 'z')
				&& !(str[index - 1] >= 'A' && str[index - 1] <= 'Z')
				&& !(str[index - 1] >= '0' && str[index - 1] <= '9'))
			{
				str[index] -= 32;
			}
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
	char result2[] = "quarante-deux; cinquante+et+un";
	char result3[] = "salut, comment tu vas ? 42mots";
	char result4[] = "";

	printf("Result: %s\n", ft_strcapitalize(result1));
	printf("Result: %s\n", ft_strcapitalize(result2));
	printf("Result: %s\n", ft_strcapitalize(result3));
	printf("Result: %s\n", ft_strcapitalize(result4));
	return 0;
}
*/