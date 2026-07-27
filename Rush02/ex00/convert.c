/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by msmiesko          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static const long long	g_scales[] = {1, 1000, 1000000, 1000000000, 1000000000000};

static int	group_count(char *nbr)
{
	int	len;
	int	groups;

	len = (int)ft_strlen(nbr);
	groups = (len + 2) / 3;
	if (groups < 1)
		groups = 1;
	return (groups);
}

static void	get_group(char *nbr, int len, int group_idx, char seg[3])
{
	int	end;
	int	i;
	int	pos;

	end = len - group_idx * 3;
	seg[0] = '0';
	seg[1] = '0';
	seg[2] = '0';
	i = 2;
	while (i >= 0)
	{
		pos = end - (2 - i) - 1;
		if (pos >= 0 && pos < len)
			seg[i] = nbr[pos];
		i--;
	}
}

static int	append_scale(char *buf, int start, int group_idx,
		t_entry *dict, int *fail)
{
	char	*word;

	if (group_idx == 0)
		return (start);
	if ((size_t)group_idx >= sizeof(g_scales) / sizeof(g_scales[0]))
	{
		*fail = 1;
		return (start);
	}
	word = dict_get(dict, g_scales[group_idx]);
	if (!word)
	{
		*fail = 1;
		return (start);
	}
	return (append_word(buf, start, word));
}

char	*convert_number(char *nbr, t_entry *dict, int *fail)
{
	char	*buf;
	int		len;
	int		groups;
	int		start;
	int		g;
	char	seg[3];

	len = (int)ft_strlen(nbr);
	groups = group_count(nbr);
	buf = (char *)malloc((size_t)(len * 20 + 64));
	if (!buf)
	{
		*fail = 1;
		return (NULL);
	}
	start = 0;
	g = groups - 1;
	while (g >= 0 && !*fail)
	{
		get_group(nbr, len, g, seg);
		if (seg[0] != '0' || seg[1] != '0' || seg[2] != '0')
		{
			start = three_digits_to_words(buf, start, seg, dict, fail);
			start = append_scale(buf, start, g, dict, fail);
		}
		g--;
	}
	if (start == 0 && !*fail)
	{
		buf[0] = '\0';
		start = append_word(buf, 0, dict_get(dict, 0));
	}
	buf[start] = '\0';
	return (buf);
}
