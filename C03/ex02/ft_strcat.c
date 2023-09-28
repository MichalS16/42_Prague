/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:40:12 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/17 16:32:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i])
	{
		i++;
	}
	while (src[j])
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
#include <stdio.h>

char	*ft_strcat(char *dest, char *src);

int main()
{
    char dest[50] = "Hello, ";
    char src[] = "world!";
    
    printf("Before concatenation: %s\n", dest);
    
    ft_strcat(dest, src);
    
    printf("After concatenation: %s\n", dest);
    
    return 0;
}
*/
