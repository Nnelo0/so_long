/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:07:39 by ebroudic          #+#    #+#             */
/*   Updated: 2024/11/07 09:51:25 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_string(char *s)
{
	int	count;

	if (!s)
		return (write(1, "(null)", 6));
	count = 0;
	while (s[count])
		write (1, &s[count++], 1);
	return (count);
}
