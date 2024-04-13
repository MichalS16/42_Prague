/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 14:23:49 by msmiesko          #+#    #+#             */
/*   Updated: 2024/04/13 14:23:49 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	char	*source;

	source = (char *) src;
	i = 0;
	while (source[i] && ((i + 1) < size))
	{
		dest[i] = source[i];
		i++;
	}

	if (size)
		dest[i] = 0;

	return (ft_strlen(src));
}
