/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:32:31 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/11 16:20:56 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	temporary;

	i = 0;
	while (i < (size / 2))
	{
		temporary = tab[i];
		tab[i] = tab[size - i -1];
		tab[size - i -1] = temporary;
		i++;
	}
}

/*
#include <stdio.h>

int main(void)
{
	int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8};
	int size;
	int i;

	size = 8;
	i = 0;
	ft_rev_int_tab(numbers ,size);
	while (i < size)
		{
		printf("%d ", numbers[i]);
		i++;
		}
	return (0);
}
*/