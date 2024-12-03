/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_digit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:27:49 by ebroudic          #+#    #+#             */
/*   Updated: 2024/11/08 08:38:04 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_digit(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}
	if (n >= 10)
	{
		count += printf_digit(n / 10);
		count += printf_char(n % 10 + '0');
	}
	else if (n < 10)
		count += printf_char(n + '0');
	return (count);
}
