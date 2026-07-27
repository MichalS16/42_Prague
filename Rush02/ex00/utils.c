/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by msmiesko          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <unistd.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_error(char *msg)
{
	write(1, msg, ft_strlen(msg));
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long long	ft_atol(char *str)
{
	long long	res;
	int		i;

	res = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

char	*ft_strtrim_ws(char *str)
{
	int		start;
	int		end;
	char	*res;
	int		i;

	start = 0;
	while (str[start] == ' ' || str[start] == '\t')
		start++;
	end = (int)ft_strlen(str) - 1;
	while (end >= start && (str[end] == ' ' || str[end] == '\t'
			|| str[end] == '\r' || str[end] == '\n'))
		end--;
	res = (char *)malloc((size_t)(end - start + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (start <= end)
		res[i++] = str[start++];
	res[i] = '\0';
	return (res);
}
