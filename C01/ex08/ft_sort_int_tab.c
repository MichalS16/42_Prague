/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 17:32:57 by msmiesko          #+#    #+#             */
/*   Updated: 2023/09/11 13:49:06 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	index;
	int	temporary;
	int	repete;

	repete = 0;
	while (repete < size)
	{
		index = 0;
		while (index < size -1)
		{
			if (tab[index] > tab[index + 1])
			{
				temporary = tab[index];
				tab[index] = tab[index + 1];
				tab[index + 1] = temporary;
			}
			index++;
		}
		repete++;
	}
}

/*
#include <stdio.h>

int main(void)
{
	int numbers[] = {9, 5, 1, 7, 3, 8, 2, 4, 6};
	int size;
	int i;

	size = 9;
	i = 0;
	ft_sort_int_tab(numbers ,size);
	while (i < size)
		{
		printf("%d ", numbers[i]);
		i++;
		}
	return (0);
}
*/