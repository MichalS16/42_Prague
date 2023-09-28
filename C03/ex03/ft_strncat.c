/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 13:23:59 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/17 14:33:33 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i])
	{
		i++;
	}
	while (src[j] && j < nb)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[j + i] = '\0';
	return (dest);
}

/*
#include <stdio.h>

// Prototype for the ft_strncat function
char	*ft_strncat(char *dest, char *src, unsigned int nb);

int main()
{
    char dest[50] = "Hello, ";
    char src[] = "world!";
    unsigned int nb = 3;

    printf("Before ft_strncat: dest = %s\n", dest);

    // Call the ft_strncat function
    ft_strncat(dest, src, nb);

    printf("After ft_strncat: dest = %s\n", dest);

    return 0;
}
*/