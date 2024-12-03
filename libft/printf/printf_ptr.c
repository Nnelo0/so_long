/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:18:27 by ebroudic          #+#    #+#             */
/*   Updated: 2024/11/08 08:37:15 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printf_hex_recursive(unsigned long long n, char *hex)
{
	int	count;

	count = 0;
	if (n >= 16)
	{
		count += printf_hex_recursive(n / 16, hex);
		count += printf_char(hex[n % 16]);
	}
	else
		count += printf_char(hex[n % 16]);
	return (count);
}

static int	ft_printf_hex(unsigned long long n, int base)
{
	char	*hex;

	if (base)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n == 0)
		return (printf_char('0'));
	else
		return (printf_hex_recursive(n, hex));
}

int	printf_ptr(unsigned long long n)
{
	int	count;

	if (n == 0)
		return (write(1, "(nil)", 5));
	count = write(1, "0x", 2);
	count += ft_printf_hex(n, 0);
	return (count);
}
