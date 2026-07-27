/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by msmiesko          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	skip_spaces(char *line, int i)
{
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	return (i);
}

static int	parse_key(char *line, int i, long long *key)
{
	int	start;

	start = i;
	*key = 0;
	while (line[i] >= '0' && line[i] <= '9')
	{
		*key = *key * 10 + (line[i] - '0');
		i++;
	}
	if (i == start)
		return (-1);
	return (i);
}

int	parse_line(char *line, long long *key, char **value)
{
	int	i;
	char	*trimmed;
	char	*raw_value;

	i = 0;
	i = skip_spaces(line, i);
	i = parse_key(line, i, key);
	if (i < 0)
		return (-1);
	i = skip_spaces(line, i);
	if (line[i] != ':')
		return (-1);
	i++;
	raw_value = line + i;
	trimmed = ft_strtrim_ws(raw_value);
	if (!trimmed)
		return (-1);
	*value = trimmed;
	return (0);
}

t_entry	*new_entry(long long key, char *value)
{
	t_entry	*e;

	e = (t_entry *)malloc(sizeof(t_entry));
	if (!e)
		return (NULL);
	e->key = key;
	e->value = value;
	e->next = NULL;
	return (e);
}

void	add_entry(t_entry **lst, t_entry *new)
{
	t_entry	*tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
