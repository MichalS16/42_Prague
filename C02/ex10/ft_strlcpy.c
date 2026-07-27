/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:32:23 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/22 10:06:37 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	index;
	unsigned int	lenght;

	index = 0;
	lenght = 0;
	while (src[lenght])
	{
		lenght++;
	}
	if (size <= 0 || dest == NULL)
	{
		return (lenght);
	}
	while (src[index] && index < size - 1)
	{
		dest[index] = src[index];
		++index;
	}
	dest[index] = '\0';
	return (lenght);
}

/*
#include <stdio.h>
int	main()
{
	char	old[] = "Hello, World!";
	char	new[20];

	printf("Copied String: %s\n", new);
	printf("Length of Copied String: %u\n", ft_strlcpy(new, old, 2));
	return 0;
}
*/