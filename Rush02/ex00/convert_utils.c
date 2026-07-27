/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by msmiesko          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	append_word(char *buf, int start, char *word)
{
	int	i;

	if (start > 0)
		buf[start++] = ' ';
	i = 0;
	while (word[i] != '\0')
		buf[start++] = word[i++];
	return (start);
}

static int	tens_and_units(char *buf, int start, int val,
		t_entry *dict, int *fail)
{
	char	*word;
	int		tens;
	int		units;

	if (val < 20)
	{
		word = dict_get(dict, val);
		if (!word)
			*fail = 1;
		else
			start = append_word(buf, start, word);
		return (start);
	}
	tens = (val / 10) * 10;
	units = val % 10;
	word = dict_get(dict, tens);
	if (!word)
	{
		*fail = 1;
		return (start);
	}
	start = append_word(buf, start, word);
	if (units > 0)
	{
		word = dict_get(dict, units);
		if (!word)
			*fail = 1;
		else
			start = append_word(buf, start, word);
	}
	return (start);
}

int	three_digits_to_words(char *buf, int start, char seg[3],
		t_entry *dict, int *fail)
{
	int	hundreds;
	int	rest;
	char	*word;

	hundreds = seg[0] - '0';
	rest = (seg[1] - '0') * 10 + (seg[2] - '0');
	if (hundreds > 0)
	{
		word = dict_get(dict, hundreds);
		if (!word)
		{
			*fail = 1;
			return (start);
		}
		start = append_word(buf, start, word);
		word = dict_get(dict, 100);
		if (!word)
		{
			*fail = 1;
			return (start);
		}
		start = append_word(buf, start, word);
	}
	if (rest > 0)
		start = tens_and_units(buf, start, rest, dict, fail);
	return (start);
}
