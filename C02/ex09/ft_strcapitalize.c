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

int	is_alnum(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if ((str[index] >= 'A' && str[index] <= 'Z'))
			str[index] += 32;
		if (str[index] >= 'a' && str[index] <= 'z')
		{
			if (index == 0 || !is_alnum(str[index - 1]))
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