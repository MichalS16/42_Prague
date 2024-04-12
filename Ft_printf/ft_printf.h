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
# include <unistd.h>

int	ft_printchar(char c);
int	ft_printf(const char *str, ...);
int	ft_printnbr(long n, int base, int uppercase);
int	ft_printptr(unsigned long long ptr);
int	ft_printstr(char *s);
#endif