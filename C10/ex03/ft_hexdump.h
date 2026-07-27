/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 00:00:00 by msmiesko          #+#    #+#             */
/*   Updated: 2026/07/27 00:00:00 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

void	ft_putstr(char *s);
void	ft_putstr_fd(char *s, int fd);
int		ft_starts_with(char *s, char *prefix);
void	ft_print_hex_byte(unsigned char c);
void	ft_print_offset(long off);
void	ft_print_ascii(unsigned char *buf, int len);
void	ft_print_hex_row(unsigned char *buf, int len);

#endif
