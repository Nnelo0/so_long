/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_udigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:02:30 by ebroudic          #+#    #+#             */
/*   Updated: 2024/11/07 10:58:31 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_udigit(unsigned int n)
{
	int	count;

	if (n == 0)
		return (printf_char('0'));
	count = 0;
	if (n >= 10)
	{
		count += printf_udigit(n / 10);
		count += printf_char(n % 10 + '0');
	}
	else
		count += printf_char(n + '0');
	return (count);
}
