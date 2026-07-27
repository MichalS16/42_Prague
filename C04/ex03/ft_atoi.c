/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:37:19 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/20 10:18:42 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	sign;
	int	number;
	int	i;

	sign = 1;
	i = 0;
	number = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
	{
		i++;
	}
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			sign *= -1;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + str[i] - '0';
		i++;
	}
	return (number * sign);
}

/*
#include <stdio.h>
int main() {
	char test_str1[] = "12345";
	char test_str2[] = "+++-+-+-+-+-678a90";
	char test_str3[] = "   +42";
	char test_str4[] = "  -56";

	int result1 = ft_atoi(test_str1);
	int result2 = ft_atoi(test_str2);
	int result3 = ft_atoi(test_str3);
	int result4 = ft_atoi(test_str4);

	printf("Result 1: %d\n", result1);
	printf("Result 2: %d\n", result2);
	printf("Result 3: %d\n", result3);
	printf("Result 4: %d\n", result4);
	return (0);
}
*/