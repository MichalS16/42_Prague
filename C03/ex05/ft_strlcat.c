/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:55:40 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/27 18:18:15 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	lengthcount(char *string)
{
	unsigned int	i;

	i = 0;
	while (string[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	lstr;
	unsigned int	ldest;

	i = 0;
	j = 0;
	while (dest[j])
	{
		j++;
	}
	ldest = j;
	lstr = lengthcount(src);
	if (size <= ldest || size == 0)
	{
		return (lstr + size);
	}
	while (src[i] && (i < size - 1 - ldest))
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (ldest + lstr);
}

/*
#include <stdio.h>
int main()
{
	char dest[20] = "1337 42";
	char src[] = "Born to code";
	unsigned int size = 20;

	printf("Before ft_strlcat: dest = \"%s\", src = \"%s\"\n", dest, src);
	printf("Return value of ft_strlcat: %u\n", ft_strlcat(dest, src, size));
	printf("After ft_strlcat: dest = \"%s\", src = \"%s\"\n", dest, src);
	return (0);
}
*/