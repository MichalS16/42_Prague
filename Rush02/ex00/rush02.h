/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by msmiesko          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <stddef.h>
# include <stdlib.h>

# define REF_DICT "numbers.dict"

typedef struct s_entry
{
	long long			key;
	char			*value;
	struct s_entry	*next;
}	t_entry;

/* dict.c */
t_entry	*load_dict(char *path, int *fail);
void	free_dict(t_entry *lst);
char	*dict_get(t_entry *lst, long long key);

/* dict_parse.c */
int		parse_line(char *line, long long *key, char **value);
t_entry	*new_entry(long long key, char *value);
void	add_entry(t_entry **lst, t_entry *new);

/* convert.c */
char	*convert_number(char *nbr, t_entry *dict, int *fail);

/* convert_utils.c */
int		three_digits_to_words(char *buf, int start, char seg[3],
			t_entry *dict, int *fail);
int		append_word(char *buf, int start, char *word);

/* utils.c */
int		is_valid_number(char *str);
long long	ft_atol(char *str);
size_t	ft_strlen(char *str);
char	*ft_strtrim_ws(char *str);
void	ft_error(char *msg);

/* utils2.c */
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*read_all(int fd);
char	**split_lines(char *content, int *count);
void	free_lines(char **lines);

#endif
