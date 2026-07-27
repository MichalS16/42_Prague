/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:37:14 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/20 17:10:58 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 5;
	if (nb == 2 || nb == 3)
	{
		return (1);
	}
	if (nb <= 1 || nb % 2 == 0 || nb % 3 == 0)
	{
		return (0);
	}
	while (i <= nb / i)
	{
		if (nb % i == 0 || nb % (i + 2) == 0)
		{
			return (0);
		}
		i = i + 6;
	}
	return (1);
}

/*
#include <stdio.h>
int main() {
    int test_cases[] = {2147483647, 1, 2, 3, 7, 78989};

    for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
        int num = test_cases[i];
        int result = ft_is_prime(num);
        if (result) {
            printf("%d is prime.\n", num);
        } else {
            printf("%d is not prime.\n", num);
        }
    }

    return 0;
}
*/