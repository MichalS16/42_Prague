/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmiesko <msmiesko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 23:28:10 by msmiesko          #+#    #+#             */
/*   Updated: 2024/04/12 23:28:10 by msmiesko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_type_option(char type, va_list args, int *len);
int		ft_printf(const char *str, ...);
void	ft_putchar_len(char c, int *len);
void	ft_putnbr(unsigned int n, int *len);
void	ft_puthexa(unsigned int n, char hex_base, int *len);
void	ft_put_hexa_adress(uintptr_t number, int *len)
void	ft_putpointer(void *ptr, int *len);
void	ft_putstr_len(char *s, int *len);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
#endif