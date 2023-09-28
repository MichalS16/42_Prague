/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:11:48 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/13 15:48:25 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	index;

	index = 0;
	while (src[index] != '\0' && index < n)
	{
		dest[index] = src[index];
		++index;
	}
	while (index < n)
	{
		dest[index] = '\0';
		index++;
	}
	return (dest);
}

/*
int	main()
{
	char new[5] = {};
	char old[] = "Hello World";
	ft_strncpy(new, old, 4);
	int	i;

	i = 0;
	while (new[i] != '\0')
	{
		write(1, &new[i], 1);
		i++;
	}
	return (0);
}
*/