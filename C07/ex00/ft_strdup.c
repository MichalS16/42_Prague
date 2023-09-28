/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:28:01 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/28 13:25:16 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	unsigned int	i;
	int 		length;
	char		*dest;

	i = 0;
	while (src[i])
	{
		i++;
	}
	length = i;
	dest = malloc(sizeof(*src) * (length + 1));
	if (dest == 0)
	{
		return (0);
	}
	i = 0;
	while (src[i] <= length)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}