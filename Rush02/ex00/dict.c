/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by msmiesko          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <fcntl.h>
#include <unistd.h>

static const long long	g_required_keys[] = {
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
	20, 30, 40, 50, 60, 70, 80, 90, 100, 1000, 1000000, 1000000000, -1
};

char	*dict_get(t_entry *lst, long long key)
{
	char	*found;

	found = NULL;
	while (lst)
	{
		if (lst->key == key)
			found = lst->value;
		lst = lst->next;
	}
	return (found);
}

static int	build_entries(char **lines, t_entry **head)
{
	int		i;
	long long	key;
	char	*value;

	i = 0;
	while (lines[i])
	{
		if (lines[i][0] != '\0')
		{
			if (parse_line(lines[i], &key, &value) < 0)
				return (-1);
			if (value[0] == '\0')
			{
				free(value);
				return (-1);
			}
			add_entry(head, new_entry(key, value));
		}
		i++;
	}
	return (0);
}

static int	has_required_keys(t_entry *lst)
{
	int	i;

	i = 0;
	while (g_required_keys[i] != -1)
	{
		if (!dict_get(lst, g_required_keys[i]))
			return (0);
		i++;
	}
	return (1);
}

t_entry	*load_dict(char *path, int *fail)
{
	int		fd;
	char	*content;
	char	**lines;
	int		count;
	t_entry	*head;

	*fail = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		*fail = 1;
		return (NULL);
	}
	content = read_all(fd);
	close(fd);
	if (!content)
	{
		*fail = 1;
		return (NULL);
	}
	lines = split_lines(content, &count);
	free(content);
	head = NULL;
	if (!lines || build_entries(lines, &head) < 0)
		*fail = 1;
	free_lines(lines);
	if (!*fail && !has_required_keys(head))
		*fail = 1;
	if (*fail)
	{
		free_dict(head);
		return (NULL);
	}
	return (head);
}

void	free_dict(t_entry *lst)
{
	t_entry	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst->value);
		free(lst);
		lst = tmp;
	}
}
