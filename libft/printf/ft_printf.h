/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:39:06 by ebroudic          #+#    #+#             */
/*   Updated: 2024/11/07 11:09:24 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

int	ft_printf(const char *s, ...);
int	printf_char(int c);
int	printf_string(char *s);
int	printf_digit(int n);
int	printf_udigit(unsigned int n);
int	printf_hex(unsigned int n, int base);
int	printf_ptr(unsigned long long n);

#endif