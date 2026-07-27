/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:13:27 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/17 14:14:40 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	if (i != n)
	{
		return (s1[i] - s2[i]);
	}
	return (0);
}

/*
#include <stdio.h>
int main() {
	char str1[] = "Hello, wbrld!";
	char str2[] = "Hello, waere!";

	int result1 = ft_strncmp(str1, str2, 7);
	int result2 = ft_strncmp(str1, str2, 12);

	printf("Result1: %d\n", result1);
	printf("Result2: %d\n", result2);

	return 0;
}
*/