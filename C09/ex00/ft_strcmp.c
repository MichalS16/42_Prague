/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 10:37:48 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/26 11:00:49 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
	{
		i++;
	}
	if (s1[i] != s2[i])
	{
		return (s1[i] - s2[i]);
	}
	return (0);
}

/*
#include <stdio.h>

int main() {
	char str1[] = "42 Prague!";
	char str2[] = "42 Prague!";
	char str3[] = "Goodbye, World!";

	int result1 = ft_strcmp(str1, str2);
	int result2 = ft_strcmp(str1, str3);
	if (result1 == 1) {
		printf("str1 and str2 are equal\n");
	} else {
		printf("str1 and str2 are not equal\n");
	}
	if (result2 == 1) {
		printf("str1 and str3 are equal\n");
	} else {
		printf("str1 and str3 are not equal\n");
	}
	return 0;
}
*/