/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnelo <nnelo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 09:51:07 by ebroudic          #+#    #+#             */
/*   Updated: 2024/10/24 21:14:33 by nnelo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*dsa;
	long	n1;
	int		len;

	n1 = n;
	len = ft_intlen(n1);
	dsa = malloc(sizeof(char) * (len + 1));
	if (dsa == NULL)
		return (NULL);
	dsa[len] = '\0';
	if (n1 == 0)
		dsa[0] = '0';
	if (n1 < 0)
	{
		dsa[0] = '-';
		n1 = -n1;
	}
	while (len > 0 && n1 > 0)
	{
		dsa[len - 1] = (n1 % 10) + '0';
		n1 /= 10;
		len--;
	}
	return (dsa);
}
/*int main()
{
	printf("%s\n", ft_itoa(-2147483648));
	return 0;
}*/