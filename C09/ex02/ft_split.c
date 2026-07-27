/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 09:50:29 by marvin            #+#    #+#             */
/*   Updated: 2023/09/24 09:50:29 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	separator(char c, char *charset)
{
	int	i;

	i = 0;
	if (c == '\0')
	{
		return (1);
	}
	while (charset[i])
	{
		if (c == charset[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	word_count(char *str, char *charset)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (separator(str[i + 1], charset) == 1
			&& separator(str[i], charset) == 0)
		{
			words++;
		}
		i++;
	}
	return (words);
}

void	copy_word(char *dest, char *src, char *charset)
{
	int	i;

	i = 0;
	while (separator(src[i], charset) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	split_words(char **array, char *str, char *charset)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	word = 0;
	while (str[i])
	{
		if (separator(str[i], charset) == 1)
		{
			i++;
		}
		else
		{
			j = 0;
			while (separator(str[i + j], charset) == 0)
			{
				j++;
			}
			array[word] = (char *)malloc(sizeof(char) * (j + 1));
			copy_word(array[word], str + i, charset);
			i += j;
			word++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**array;

	array = (char **)malloc(sizeof(char *) * (word_count(str, charset) + 1));
	array[word_count(str, charset)] = 0;
	split_words(array, str, charset);
	return (array);
}

/*
int main()
{
	char input_string[] = "This,is,a,test,string";
	char charset[] = ",";
	char **result = ft_split(input_string, charset);

	for (int i = 0; result[i] != NULL; i++)
	{
		printf("Word %d: %s\n", i, result[i]);
		free(result[i]);
	}
	free(result);
	return (0);
}
*/