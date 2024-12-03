/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebroudic <ebroudic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:50:19 by ebroudic          #+#    #+#             */
/*   Updated: 2024/11/07 11:17:00 by ebroudic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_afterpurcent(const char *s, int i, va_list list)
{
	int	count2;

	count2 = 0;
	if (s[i] == 'c')
		count2 += printf_char(va_arg(list, int));
	else if (s[i] == 's')
		count2 += printf_string(va_arg(list, char *));
	else if (s[i] == 'p')
		count2 += printf_ptr(va_arg(list, unsigned long long));
	else if (s[i] == 'd' || s[i] == 'i')
		count2 += printf_digit(va_arg(list, int));
	else if (s[i] == 'u')
		count2 += printf_udigit(va_arg(list, unsigned int));
	else if (s[i] == 'x')
		count2 += printf_hex(va_arg(list, unsigned int), 0);
	else if (s[i] == 'X')
		count2 += printf_hex(va_arg(list, unsigned int), 1);
	else if (s[i] == '%')
		return (printf_char('%'));
	return (count2);
}

int	ft_printf(const char *s, ...)
{
	va_list	list;
	int		count;
	int		i;

	va_start(list, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			count += ft_afterpurcent(s, i, list);
		}
		else
			count += write(1, &s[i], 1);
		i++;
	}
	va_end(list);
	return (count);
}

/* int main()
{
	int	i;
 	void *b = "hello";

	i = ft_printf("%p\n",b);
	ft_printf("[%d]\n", i);
	i = ft_printf("%p\n", b);
	printf("[%d]\n", i);
 	return (0);
} */
