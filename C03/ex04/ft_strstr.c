/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:32:50 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/17 14:33:19 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[i] == '\0')
	{
		return (str);
	}
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			j++;
			if (to_find[j] == '\0')
			{
				return (str + i);
			}
		}
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
int main()
{
    char str[] = "This is a sample string.";
    char to_find[] = "sample";

    char *result = ft_strstr(str, to_find);

    if (result != NULL)
	{
        printf("Substring found at position: %ld\n", result - str);
    }
	else
	{
        printf("Substring not found in the string.\n");
	}
    return 0;
}
*/